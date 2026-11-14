#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

ll MOD = 1e9+7;

ll modPow(ll a, ll b){
    ll ans = 1;

    a %= MOD;
    while(b > 0){
        if(b&1) ans = (ans*a) % MOD;
        a=(a*a)%MOD;
        b>>=1;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    for(int i = 0; i< n; i++){
        ll a,b;
        cin >> a >> b;

        cout << modPow(a,b) << endl;

    }
    


    
    return 0;
}
