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
        ll l, r;
        cin >> l >> r;
        if(l * 2 > r) cout << "-1 -1" << endl;
        else cout << l << " " << l*2 << endl;
    }
    
    return 0;
}
