#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = (a); i < (ll)(b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (ll)(x).size()
#define input(val, n) rep(i, 0, n) cin >> val[i]
typedef long long ll;

typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const ll INF = (ll)1e18, MOD = (ll)1e9 + 7;



ll helper(ll i, vector<pair<string, string>>& collars, ll k1, ll k2, unordered_map<string, ll>& pattern, unordered_map<string, ll>& colour){
    if(i >= collars.size()) return 0;

    ll skip = helper(i+1, collars, k1, k2, pattern, colour);
    ll take = 0;
    string col = collars[i].first, pat = collars[i].second;
    if(pattern[pat] < k2 && colour[col] < k1){
        pattern[pat]++; colour[col]++;

        take = 1+helper(i+1, collars, k1, k2, pattern, colour);

        pattern[pat]--; colour[col]--;
    }

    return max(skip, take);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, k1, k2; 
    cin >> n >> k1 >> k2;

    vector<pair<string, string>> collars(n);

    unordered_map<string, ll> pattern, colour;

    rep(i, 0, n){
        string a,b;
        cin >> a >> b; 
        collars[i] = {a,b};
    }

    cout << helper(0, collars, k1, k2, pattern, colour) << endl;

    return 0;
}