#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    vector<ll> vals(n);
    vals[0] = x;

    for(int i=1; i < n; i++) vals[i] = (a*vals[i-1] + b) % c;

    vector<ll> prefix(n+1, 0);
    for(int i = 1; i <= n; i++) prefix[i] = vals[i-1] ^ prefix[i-1];

    ll ans = 0;
    for(int i = k; i <= n; i++) ans ^= prefix[i] ^ prefix[i - k];


    cout << ans << endl;
    
    return 0;
}
