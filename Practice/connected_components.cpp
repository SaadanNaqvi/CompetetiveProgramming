#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

using vi = vector<ll>;


vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> forbidden(n);
    for(int i = 0; i < m; i++){
        ll a,b;
        cin >> a >> b;
        a--, b--;
        forbidden[a].push_back(b);
        forbidden[b].push_back(a);
    }

    vector<ll> sizes;
    scc(forbidden, [&](vi& c){
        sizes.push_back((ll)c.size());
    });

    cout << sizes.size() << endl;
    sort(all(sizes));
    for(auto& x:sizes) cout << x << " ";
    cout << endl;
    
    return 0;
}
