//Code is like humour , when you have to explain it its bad

#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define all(v) v.begin(),v.end()

int n,m;


vector <vector<int>> connectedCompnents;
vector<int> curr;

map<int,set<int>> graph;

void dfs(int vertex , bool vis[]){
    //after entering the vertex
    vis[vertex]=1;
    curr.push_back(vertex);
    //if(vis[vertex]) return;

    for(int child : graph[vertex]){
        
        //before entering the child
        if(vis[child])continue;
        dfs(child,vis);
       
        //after exiting ther child node 
    }
    //before exiting the vertex
}


signed main()
{   
    int t=1;//cin>>t;
    while(t--){
        
        cin>>n>>m;
        bool vis[n]={0};

        for (int i = 1; i <= n; i++)
        {
            graph[i]={i};
        }
    
        for(int i = 0 ; i < m; i++){
            int x;cin>>x;
            set<int> v;

            for(int j =0 ; j < x;j++){
                int a;cin>>a;
                v.insert(a);
            }

            for(auto x : v){
                graph[x].insert(all(v));
            }
        }
        for(int i = 1 ; i <= n; i++){
            if(vis[i]) continue;
            dfs(i,vis);
            connectedCompnents.push_back(curr);
            curr.clear();
        }

        vector<int>ans(n+1,0);
        for(auto i : connectedCompnents){
            for(auto j : i){
                ans[j]=i.size();
            }
        }

        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
    }       
}