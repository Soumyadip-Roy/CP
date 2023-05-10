#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> graph[N];

bool vis[N];

vector <vector<int>> connectedCompnents;
vector<int> curr;

void dfs(int vertex){

    //after entering the vertex
    vis[vertex]=1;
    curr.push_back(vertex);
    //if(vis[vertex]) return;

    for(int child : graph[vertex]){
        
        //before entering the child
        if(vis[child])continue;
        dfs(child);
       
        //after exiting ther child node 
    }
    //before exiting the vertex
}

int main(){
    
    int n , m; //n vertices , m edges 
    cin>>n>>m;

    for(int i = 0 ; i < m; i++){
        int x , y ;
        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ct = 0;

    for(int i = 1 ; i <= n; ++i){
        if(vis[i]) continue;
        dfs(i);
        connectedCompnents.push_back(curr);
        curr.clear();
        ct++;
    }

    cout<<ct<<endl;
    for(auto i : connectedCompnents){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
