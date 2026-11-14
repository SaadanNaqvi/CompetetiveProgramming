#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

vector<unordered_map<ll, ll>> memo;

ll helper(ll i, vector<ll>& vals, ll k, ll value = 1){
    if(k == 0){
        string str = to_string(value);
        ll zCount = 0;
        for(auto& c: str){
            if(c == '0') zCount++;
            else zCount = 0;
        }
        return zCount;
    }
    if(k < 0 || i == vals.size()) return -1e9;

    if(memo[k].count(value)) return memo[k][value];

    ll skip = helper(i+1, vals, k, value);

    ll take = helper(i+1, vals, k-1, value * vals[i]);

    return memo[k][value] = max(skip, take);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    vector<ll> vals(n);
    for(int i = 0; i < n; i++) cin >> vals[i];
    memo.resize(k+1);
    cout << helper(0, vals, k) << endl;


    
    return 0;
}
