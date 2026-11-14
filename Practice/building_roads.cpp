#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

unordered_set<ll> seen;

void dfs(ll i, vector<vector<ll>>& adjList){
    seen.insert(i);

    for(auto& neigh: adjList[i]){
        if(!seen.count(neigh)) dfs(neigh, adjList);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adjList(n);

    for(int i = 0; i < m; i++){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<ll> output;

    for(int i = 0; i < n; i++){
        if(!seen.count(i)){
            output.push_back(i);
            dfs(i, adjList);
        }
    }

    cout << output.size()-1 << endl;

    for(int i = 0; i < output.size()-1; i++){
        cout << output[i]+1 << " " << output[i+1]+1 << endl;
    }
    
    return 0;
}
