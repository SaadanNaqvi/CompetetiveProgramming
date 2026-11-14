#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) {
        return (a + b); 
    } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos) {
        pos += n;

        s[pos]++;
		for (pos /= 2;pos;pos/=2)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> vals(n);
        input(vals, n);

        vector<ll> sorted = vals;
        sort(all(sorted));

        Tree tr(n);

        ll inversions = 0;

        for(int i = 0; i < n; i++){
            int pos = lower_bound(all(sorted), vals[i])-sorted.begin();
            inversions += tr.query(pos+1, n);
            tr.update(pos);
        }

        cout << inversions << endl;
    }
    
    return 0;
}
