#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for (ll i = 0; i < n; i++) cin >> val[i]

struct DST {
    using T = ll;

    int n, levels;
    T mod;

    vector<T> a;
    vector<vector<T>> table;

    DST(vector<T>& vals, T p) {
        n = vals.size();
        mod = p;
        a = vals;

        // Store values modulo p
        for (auto& x : a)
            x %= mod;

        levels = 1;
        while ((1LL << levels) < n)
            levels++;

        table.assign(levels, vector<T>(n));

        build();
    }

    T f(T a, T b) {
        return (__int128)a * b % mod;
    }

    void build() {

        // k determines block half-size = 2^k
        for (int k = 0; (1LL << k) < n; k++) {

            int half = 1 << k;
            int blockSize = half << 1;

            for (int start = 0; start < n; start += blockSize) {

                int mid = min(start + half, n);
                int end = min(start + blockSize, n);

                // -------------------------
                // LEFT HALF
                // Store suffix products
                //
                // [a b c | d e f]
                //
                // c
                // b*c
                // a*b*c
                // -------------------------

                if (mid > start) {

                    table[k][mid - 1] = a[mid - 1];

                    for (int i = mid - 2; i >= start; i--) {
                        table[k][i] =
                            f(a[i], table[k][i + 1]);
                    }
                }

                // -------------------------
                // RIGHT HALF
                // Store prefix products
                //
                // [a b c | d e f]
                //
                // d
                // d*e
                // d*e*f
                // -------------------------

                if (mid < end) {

                    table[k][mid] = a[mid];

                    for (int i = mid + 1; i < end; i++) {
                        table[k][i] =
                            f(table[k][i - 1], a[i]);
                    }
                }
            }
        }
    }

    // Inclusive query [l, r]
    T query(int l, int r) {

        if (l == r)
            return a[l];

        // Highest bit where l and r differ
        int k = 63 - __builtin_clzll((ll)l ^ r);

        return f(table[k][l], table[k][r]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        ll p, q;

        cin >> n >> p >> q;

        vector<ll> vals(n);
        input(vals, n);

        // Build disjoint sparse table
        DST dst(vals, p);

        ll qNum = q / 64 + 2;

        vector<ll> b(qNum);
        input(b, qNum);

        ll x = 0;
        int l = 0, r = 0;

        for (ll i = 0; i < q; i++) {

            if (i % 64 == 0) {

                l = (b[i / 64] + x) % n;
                r = (b[i / 64 + 1] + x) % n;
            }
            else {

                l = (l + x) % n;
                r = (r + x) % n;
            }

            if (l > r)
                swap(l, r);

            // DST query is inclusive [l, r]
            x = (dst.query(l, r) + 1) % p;
        }

        cout << x << '\n';
    }

    return 0;
}