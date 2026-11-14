#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]
using vi = vector<ll>;

const ll inf = 1e18;
struct Node {
	Node *l = 0, *r = 0;
	ll lo, hi, mset = inf, madd = 0, val = 0;
	Node(ll lo,ll hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, ll lo, ll hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			ll mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = l->val + r->val;
		}
		else val = v[lo];
	}
	ll query(ll L, ll R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
	}
	void set(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = x, val = x * (hi - lo), madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = l->val + r->val;
		}
	}
	void add(ll L, ll R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x * (hi - lo);
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = l->val+r->val;
		}
	}
	void push() {
        if (lo + 1 == hi) return;
		if (!l) {
			ll mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q;
    cin >> n >> q;

    vector<ll> vals(n);
    input(vals, n);

    Node tree(vals, 0, n);

    while(q--){
        ll choice;
        cin >> choice;
        if(choice == 1){
            ll a,b,u;
            cin >> a >> b >> u;

            tree.add(a-1, b, u);
        }
        else{
            ll k;
            cin >> k;

            cout << tree.query(k-1, k) << endl;
        }
    }
    
    return 0;
}
