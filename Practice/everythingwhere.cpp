#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;
        vector<ll> vals(n);

        for(int i = 0; i < n; i++) cin >> vals[i];

        ll ans = 0;

        for(ll i = 0; i < n-1; i++){
            ll target = abs(vals[i] - vals[i+1]);
            if(target == gcd(vals[i], vals[i+1])) ans++;
        }

        cout << ans << endl;


    }
    
    return 0;
}
