//Check if the given graph is connected or not

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define rep(n) for(int i=0;i<n;++i)
int mod=1000000007;
using namespace std;
int visited[100005];
vector<int> adj[100005];

void dfs(int s){
    if(visited[s])return;
    visited[s]=true;
    for(auto u : adj[s]){
        dfs(u);
    }
}


int32_t main() {
    fast;
    int t;
    //cin>>t;
    t=1;
    while(t--){
      int n,m;
      cin>>n>>m;
      rep(m){
          int u,v;
          cin>>u>>v;
          --u;--v;
          adj[u].push_back(v);
          adj[v].push_back(u);
      }

      dfs(0);
      
      int flag=1;

      rep(n)if(visited[i]==false)flag=0;
      
      cout<< ((flag==1) ? "Yes":"No") <<'\n';
    }//end of tt
}