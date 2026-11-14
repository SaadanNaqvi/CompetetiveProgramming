#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

bool dfs(vector<vector<ll>>& adjList, vector<ll>& assignTeams, ll i = 0, ll color = 1){
    
    assignTeams[i] = color;

    for(auto& neigh: adjList[i]){
        if (assignTeams[neigh] == 0){
            if(!dfs(adjList, assignTeams, neigh, 3-color)) return false;
        }
        else if(assignTeams[neigh] == assignTeams[i]) return false;
        
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;

    vector<vector<ll>> adjList(n);

    for(int i = 0; i < m; i++){
        ll a,b;
        cin >> a >> b;
        a--, b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<ll> assignTeams(n, 0);
    for (int i = 0; i < n; i++) {
        if (assignTeams[i] == 0) {
            if (!dfs(adjList, assignTeams, i, 1)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for(auto team:assignTeams) cout << team << " ";

    cout << endl;
    
    return 0;
}
