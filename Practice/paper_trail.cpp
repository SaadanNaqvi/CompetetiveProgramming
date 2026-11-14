#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

struct Tree {
    typedef int T;
    static constexpr T unit = INT_MAX;

    T f(T a, T b) {
        return min(a, b);
    }

    vector<T> s;
    int n;

    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}

    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }

    T query(int b, int e) {
        T ra = unit, rb = unit;

        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }

        return f(ra, rb);
    }
};

template<class T> struct Compressor{
    vector<T> sorted; // the d i s t i n c t values , increasing
    Compressor(vector<T> values) : sorted(values) {
        sort(all(sorted));
        sorted.erase(unique(all(sorted)), sorted.end());
    }
    int rank(T value) {
        auto it = lower_bound(all(sorted), value);
        return int(it - sorted.begin());
    }
    int size() { return sorted.size(); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> vals(n);

    input(vals,n);
    vector<ll> prefix(n + 1);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + vals[i];
    }


    Compressor<ll> comp(vals);

    Tree tr(comp.size());
    vector<ll> ans(n);
    vector<ll> stored(comp.size(), 0);
    for (ll i = n - 1; i >= 0; i--) {
        int r = comp.rank(vals[i]);

        ans[i] = tr.query(r + 1, comp.size());

        int blocker = tr.query(r, comp.size());

        if (blocker == INT_MAX) {
            ans[i] = prefix[n] - prefix[i + 1];
        }
        else {
            ans[i] = prefix[blocker] - prefix[i + 1];
        }

        tr.update(r, i);
    }


    for (ll x : ans) {
        cout << x << " ";
    }
    cout << endl;


    
    return 0;
}
