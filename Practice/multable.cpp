#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll need = (n * n + 1)/2;

    ll l = 1, r = n * n, ans = 1;

    while(l <= r){
        ll mid = l + (r-l)/2;

        ll count = 0;

        for(ll i = 1; i <= n; i++) count += min(n, mid/i);

        if(count >= need){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    
    cout << ans << endl;
    return 0;
}
