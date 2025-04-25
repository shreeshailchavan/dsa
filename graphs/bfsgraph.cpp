#include<bits/stdc++.h>
using namespace std;



// class Graph{
//     private:
//         int E;
//         vector<vector<pair<int,int>>> adjList;

//     public:
//         Graph(int E){
//         this->E = E;
//         adjList.resize(E+1);
//     }

// //  u-> node1 v -> node2 weight
//     void insertEdge(int u,int v,int weight=1){
//         // adding edge from u -> v
//         adjList[u].push_back({v,weight});
//     }
//     void print(){
//         int i=0;
//         for(auto it:adjList){
//             cout << "Edge " << i <<" -> [";
//             for(auto v:it){
//                 cout << "{"<<v.first <<"," << v.second <<"},";
//             }
//             cout << "]"<<endl;
//             i++;
//         }
//     }

//     void bfsOnGraph(){
//         queue<int> q;
//         vector<int> bfs;
//         int visited[E] = {0};
//         q.push(1);
//         visited[1] = 1;
//         while(!q.empty()){
//             int node = q.front();
//             q.pop();
//             bfs.push_back(node);
//             for(auto it:adjList[node]){
//                 if(!visited[it.first]){
//                     visited[it.first] = 1;
//                     q.push(it.first);                    
//                 }
//             }
//         }

//         cout << "BFS : "<<endl;
//         for(auto it:bfs){
//             cout << it << " ";
//         }

//     }

// };

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adjList(n+1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin >> u >> v ;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // bfs 
    queue<int> q;
    vector<int> bfs;
    vector<int> visited(n+1,0);
    // 1 based indexed grap
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it:adjList[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }

    cout << "\nBFS : "<<endl;
    // bfs 
    for(auto it:bfs){
        cout << it << " ";
    }


    return 0;
}