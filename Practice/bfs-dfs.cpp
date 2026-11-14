#include <bits/stdc++.h>
using namespace std;

const int mxn=4097;
int n,dfs[mxn],bfs[mxn];
vector<pair<int,int>> edges;

int main(){
    cin.tie()->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> bfs[i];
    for(int i=1;i<=n;i++)
        cin >> dfs[i];
    if(dfs[2]!=bfs[2]){
        cout << -1;
        return 0;
    }
    for(int i=2;i<=n;i++)
        edges.push_back({1,bfs[i]});
    for(int i=2;i<n;i++)
        edges.push_back({dfs[i],dfs[i+1]});
    cout << edges.size() << "\n";
    for(auto i:edges)
        cout << i.first << ' ' << i.second << "\n";
}