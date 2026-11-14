#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]
string cowType;

bool dfs(ll cur, ll end, char target, vector<vector<ll>>& adjList, bool satisfied = false, ll parent = -1){
    if(cowType[cur] == target) satisfied = true;
    if(cur == end && !satisfied) return false;
    else if(cur == end && satisfied) return true;

    for(auto& neigh: adjList[cur]){
        if(neigh != parent) if(dfs(neigh, end, target, adjList, satisfied, cur)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    cowType.resize(n+1);
    for(int i = 1; i <=n; i++) cin >> cowType[i];

    vector<vector<ll>> adjList(n+1);
    for(int i = 0; i < n-1; i++){
        ll a,b;
        cin >> a >> b;
        adjList[a].emplace_back(b);
        adjList[b].emplace_back(a);
    }

    while(m--){
        ll start, end;
        char type;
        cin >> start >> end >> type;
        if(dfs(start, end, type, adjList)) cout << '1';
        else cout << '0';
    }
    cout << endl;
    
    return 0;
}
