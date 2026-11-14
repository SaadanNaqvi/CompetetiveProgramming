#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

// prev = 1 sport, prev = 2 contest, prev = 0 rest

vector<vector<ll>> memo;

ll helper(ll i, vector<ll>& days, ll prev = 0){
    if(i == days.size()) return 0;

    ll type = days[i];
    if(memo[i][prev] != -1) return memo[i][prev];
    bool isContest = false, isGym = false;

    if(type == 1) isContest = true;
    else if(type == 2) isGym = true;
    else if(type == 3) {isGym = true; isContest = true;}

    ll ans = 1+helper(i+1, days, 0);

    if(isGym && prev != 1) ans = min(ans, helper(i+1, days, 1));
    if(isContest && prev != 2) ans = min(ans, helper(i+1, days, 2));

    return memo[i][prev] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<ll> days(n);

    for(int i =0; i < n; i++) cin >> days[i];

    memo.resize(n+1, vector<ll>(3, -1));


    cout << helper(0, days) << endl;

    
    return 0;
}
