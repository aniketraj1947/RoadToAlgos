//Print all the components of a graph

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
bool flag=false;
unordered_set<int> ss;

void dfs(int s){
    if(visited[s])return;
    flag=true;
    visited[s]=true;
    cout<<s+1<<" ";
    ss.insert(s);
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
      int count=0;
      rep(n){     
         if(ss.find(i)==ss.end()){
            cout<<"Component "<<count+1<<" : ";
            dfs(i);
            cout<<'\n';
            count++;
         }
      }
      cout<<"Total there are "<<count<<" components."<<'\n';
    }//end of tt
}