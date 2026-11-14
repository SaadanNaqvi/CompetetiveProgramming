#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

vector<ll> subordinates;

ll helper(ll i, unordered_set<ll>& seen, vector<vector<ll>>& adjList){
    ll count = 0;
    seen.insert(i);

    for(auto& neigh:adjList[i]){
        if(!seen.count(neigh)){
            count += 1+helper(neigh, seen, adjList);
        }
    }


    return subordinates[i] = count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    subordinates.resize(n+1, 0);
    unordered_set<ll> seen;
    vector<vector<ll>> adjList(n+1);
    for(int i = 0; i < n-1; i++){
        ll boss; cin >> boss;
        adjList[boss].emplace_back(i+2);
    }

    helper(1, seen, adjList);
   
   for(int i = 1; i <= n; i++) cout << subordinates[i] << " ";
   cout << endl;
    
    return 0;
}
