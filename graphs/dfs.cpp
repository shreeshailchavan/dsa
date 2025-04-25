#include<bits/stdc++.h>
using namespace std;


void dfs(int node,vector<vector<int>>& adj_list,vector<int>& visited,vector<int>& ls){
    if(visited[node])
        return;
    visited[node] = 1;
    for(auto it:adj_list[node]){
        if(!visited[it])
            dfs(it,adj_list,visited,ls);
    }
    ls.push_back(node);
}

void print(vector<vector<int>>& adj_list){
    for(int i=1;i<adj_list.size();i++){
        cout << i << "-> [";
        for(int j=0;j<adj_list[i].size();j++){
            cout << adj_list[i][j] << " ";
        }
        cout << "]"<<endl;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    // adjacency list
    // undirected grapj
    vector<vector<int>> adj_list(n+1);
    // input the edges : 
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }


    print(adj_list);
    cout << "DFS "<<endl;
    // perform dfs search
    vector<int> ls;
    vector<int> visited(n,0);
    // starting node for dfs
    int start = 1;
    dfs(start,adj_list,visited,ls);

    for(auto it:ls)
        cout << it << " ";

    return 0;



}