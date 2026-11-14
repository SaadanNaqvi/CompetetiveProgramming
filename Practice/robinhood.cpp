#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

bool helper(vector<ll>& wealth, ll richestIndex, ll x){
    ll n = wealth.size();
    ll amountUnhappy = 0;

    wealth[richestIndex] += x;

    ll totalWealth = 0;
    for(auto& w:wealth) totalWealth += w;

    double average = (totalWealth/(n * 1.0))/2.0;

    for(auto& w:wealth) if((w * 1.0) < average) amountUnhappy++;


    wealth[richestIndex] -= x;

    return amountUnhappy > floor(n/2.0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        vector<ll> wealth(n);
        ll richestIndex = 0;
        ll richest = 0;
        for(ll i = 0; i < n; i++){ cin >> wealth[i]; if(richest < wealth[i]) {richest = wealth[i]; richestIndex = i;}}


        ll l = 0, r = 2e16, ans = -1;
        while(l <= r){
            ll mid = l + (r-l)/2;

            if(helper(wealth, richestIndex, mid)){
                ans = mid;
                r = mid -1;
            }
            else l = mid+1;
        }

        cout << ans << endl;
    }
    
    return 0;
}
