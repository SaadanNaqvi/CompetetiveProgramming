#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]



void dfs(ll i, vector<vector<ll>>& adjList, unordered_set<ll>& seen){
    seen.insert(i);

    for(auto& neigh: adjList[i]){
        if(!seen.count(neigh)){
            dfs(neigh, adjList, seen);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;

    vector<vector<ll>> adjList(n), radjList(n);
    for(int i = 0; i < m; i++){
        ll a,b;
        cin >> a >> b;
        a--,b--;
        adjList[a].emplace_back(b);
        radjList[b].emplace_back(a);
    }

    unordered_set<ll> seen1, seen2;
    vector<pair<ll, ll>> notSeen;

    dfs(0, adjList, seen1);
    dfs(0, radjList, seen2);

    for(int i = 0; i < n; i++){
        if(!seen1.count(i)){
            cout << "NO\n";
            cout << 1 << " " << i + 1 << "\n";
            return 0;
        }
        
    }
    for(int i = 0; i < n; i++){
        if(!seen2.count(i)){
            cout << "NO\n";
            cout << i + 1 << " " << 1 << "\n";
            return 0;
        }
    }

    cout << "YES" << endl;
    

    
    return 0;
}
