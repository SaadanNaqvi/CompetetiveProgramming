#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

ll dfs(ll i, ll parent, ll minRel, vector<vector<pair<ll, ll>>>& adjList, ll curRel = numeric_limits<ll>::max()){
    ll count = 0;

    for(auto& [neigh, rel]: adjList[i]){
        ll tempRel = min(curRel, rel);
        if(neigh != parent && tempRel >= minRel){
            count += 1 + dfs(neigh, i, minRel, adjList, tempRel);
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q;
    cin >> n >> q;

    vector<vector<pair<ll, ll>>> adjList(n+1);

    for(int i = 0; i < n-1; i++){
        ll p,q,r;
        cin >> p >> q >> r;
        adjList[p].push_back({q,r});
        adjList[q].push_back({p,r});
    }

    while(q--){
        ll k, vid;
        cin >> k >> vid;
        cout << dfs(vid, -1, k, adjList) << endl;
    }
    
    return 0;
}
