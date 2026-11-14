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
        string str;
        cin >> str;

        vector<ll> freq(26, 0);
        for(char c:str) freq[c-'a']++;

        priority_queue<pair<ll, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.push({freq[i], (char)('a' + i)});
        }

        string ans = "";
        pair<ll, char> prev = {-1, '#'};

        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();

            ans += cur.second;
            cur.first--;
            if(prev.first > 0) pq.push(prev);
            prev = cur;
        }

        if(ans.size() == str.size()){
            cout << "Yes" << endl;
            cout << ans << endl;
        }
        else cout << "No" << endl;

    }
    
    return 0;
}
