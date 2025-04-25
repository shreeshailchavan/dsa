#include<bits/stdc++.h>
using namespace std;


int main(){

    // nodes-> n edges -> m;
    int n,m;
    cin>>n;
    cin>>m;
    // 1 based index of graph
    int adj_matrix[n+1][n+1];
    // Adjacency list
    vector<vector<int>> adjList(n+1);

    memset(adj_matrix,0,sizeof(adj_matrix));

    // input of edges;
    for(int i=0;i<m;i++){
        // edges between two nodes u->v;
        int u,v;
        cin >> u >> v;
        // undirected graph
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;

        // undirected adj list
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }


    for(int i=1;i<=n;i++){
        cout << "[";
        for(int j=1;j<=n;j++){
            cout << adj_matrix[i][j] << " ";
        }
        cout << "]"<<endl;
    }

    // adj matrix is costly as it uses O(n^2) space

    for(int i=1;i<=n;i++){
        cout << i << "->["; 
        for(int j=1;j< adjList[i].size();j++){
            cout<<adjList[i][j] << " ";
        }
        cout << "]"<<endl;
    }
    // adj list uses space complexity of O(2n)

    return 0;
}