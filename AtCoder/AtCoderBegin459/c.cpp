#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

const ll MAX_ = 670000; 
ll bit[MAX_+1];

void update(ll idx, ll val){
    idx++;
    for (; idx < MAX_; idx += idx & -idx) bit[idx] += val;
}

ll query(ll idx){
    idx++;
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin >> n >> q;

    vector<ll> heights(n + 1, 0);
    ll offset = 0;
    ll zeroHeights = n;

    update(0, n);

    while (q--){
        ll type;
        cin >> type;
        if (type == 1) {
            ll x;
            cin >> x;
            
            update(heights[x], -1);
            if (heights[x] == offset) zeroHeights--;
            heights[x]++;
            update(heights[x], 1);
            if (zeroHeights == 0){
                offset++;
                zeroHeights = query(offset)-query(offset-1);
            }
        } 
        else{
            ll y;
            cin >> y;
            ll target = y+offset;
            
            if(target >= MAX_) cout << 0 << endl;
            else cout << n-query(target-1) << endl;
        }
    }

    return 0;
}