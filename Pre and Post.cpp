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
const int N=100005;
using namespace std;

int visited[N];
vector<int> adj[N];
queue<int> q;
int distancee[N];
int count2[N];
int pre[N];
int post[N];
int timee=1;

void bfs(int x){
    visited[x] = true;
    distancee[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        // process node s
        for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        distancee[u] = distancee[s]+1;
        q.push(u);
        }
    }
}

void dfs(int s){
    if(visited[s])return;
    visited[s]=true;
    pre[s]=timee;
    timee++;
    for(auto u : adj[s]){
        dfs(u);
    }
    post[s]=timee;
    ++timee;
}

void dfs(int s, int p){
    count2[s]=1;
    for(auto u : adj[s]){
        if(u==p)continue;
        dfs(u,s);
        count2[s] = count2[s] + count2[u];
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

      rep(n){
		  cout<<pre[i]<<" "<<post[i]<<'\n';
	  }
    }//end of tt
}