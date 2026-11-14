#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

map<pair<ll ,ll>, ll> memo;
ll h, w;
ll MOD = 1e9+7;

ll helper(ll i, ll j, set<pair<ll, ll>>& grid){
    if(i < 0 || j < 0 || i > h || j > w || grid.count({i, j})) return 0;
    if(i == h && j == w) return 1;

    if(memo.count({i, j})) return memo[{i, j}];

    ll down = helper(i+1, j, grid);
    ll right = helper(i, j+1, grid);

    return memo[{i, j}] = (down + right) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> h >> w >> n;

    set<pair<ll, ll>> grid;

    while(n--){
        ll x,y;
        cin >> x >> y;
        grid.insert({x,y});
    }
    
    cout << helper(1, 1, grid) << endl;
    
    return 0;
}
