#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define input(val, n) for(ll i = 0; i < n; i++) cin >> val[i]

bool can(vector<ll>& nums, ll mid, ll k){
    ll curGroup = 1;
    ll sums = 0;
    ll n = nums.size();

    for(int i = 0; i < n; i++){
        if(sums+nums[i] > mid){
            curGroup++;
            sums = nums[i];
        }
        else{
            sums += nums[i];
        }
    }
    if(curGroup > k) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    vector<ll> nums(n);
    ll highest = 0;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        highest = max(highest, nums[i]);
    }

    ll l = highest, r = 1e15;

    while(l < r){
        ll mid = l + (r-l)/2;
        if(can(nums, mid, k)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }

    cout << l << endl;
    
    return 0;
}
