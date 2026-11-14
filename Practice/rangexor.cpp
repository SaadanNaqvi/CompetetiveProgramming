#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;
    vector<ll> val(n);
    input(val, n);

    vector<ll> prefix(n+1, 0);
    for(int i = 1; i <= n; i++) prefix[i] = val[i-1] ^ prefix[i-1];

    
    while(q--){
        ll l,r;
        cin >> l >> r;

        ll ans = prefix[r] ^ prefix[l-1];

        cout << ans << endl;
    }
    return 0;
}
