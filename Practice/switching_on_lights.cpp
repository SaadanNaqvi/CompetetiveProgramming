#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

set<pair<ll, ll>> seen;
vector<pair<ll, ll>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
ll dfs(ll i, ll j, vector<vector<ll>>& grid, map<pair<ll, ll>, vector<pair<ll, ll>>>& rooms){
    int n = grid.size();
    if(i < 1 || i >= n || j < 1 || j >= n || grid[i][j] != 1 || seen.count({i,j})) return 0;
    seen.insert({i,j});
    ll ans = 0;
    
    for(auto& [x,y]: rooms[{i,j}]){
        if(grid[x][y] != 1){
            grid[x][y] = 1;
            ans++;
            //cout << x << " " << y << endl;
            for (auto& [dx, dy] : dir) {
                if (seen.count({x + dx, y + dy})) {
                    ans += dfs(x, y, grid, rooms);
                    break;
                }
            }
        }
    }

    
    for(auto& [x,y]:dir){
        ll dx = x + i, dy = y+j;
        ans += dfs(dx, dy, grid, rooms);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;

    vector<vector<ll>> grid(n+1, vector<ll>(n+1, 0));
    map<pair<ll, ll>, vector<pair<ll, ll>>> rooms;
    grid[1][1] = 1;

    for(int i = 0; i < m; i++){
        ll x,y,a,b;
        cin >> x >> y >> a >> b;
        rooms[{x,y}].push_back({a,b});
    }

    cout << dfs(1,1,grid, rooms)+1 << endl;

    
    return 0;
}
