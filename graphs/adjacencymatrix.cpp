#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int V;
        vector<vector<int>> adjMatrix;
        bool directedGrap = false;
    public:
        Graph(int V,bool directedGrap=false){
            this->V = V;
            adjMatrix.resize(V,vector<int>(V,0));
            this->directedGrap = directedGrap;
        }
    // undirected weighted if the weight is passed otherwise undirected
        void insertEdge(int u,int v,int weight=1){
            if(!this->directedGrap){
            adjMatrix[u][v] = weight;
            adjMatrix[v][u] = weight;
            }
            // directed and weighted graph
            else{
                adjMatrix[u][v] = weight;
            }
        }




        void print(){
            for(auto& it:adjMatrix){
                cout <<"[ ";
                for(int i:it){
                    cout << i << " ";
                }
                cout << "]"<<endl;
            }

        }
};

int main(){
    int V = 5;
    Graph g(5);
    cout << "Undirected Weighted : "<<endl;
    g.insertEdge(1,2,10);
    g.insertEdge(3,4,15);
    g.insertEdge(3,4,20);
    g.insertEdge(4,2,30);
    g.insertEdge(4,4,50);

    g.print();

    // directed graph
    cout << "Directed weighted" << endl;
    Graph dg(5,true);
    dg.insertEdge(1,2,30);
    dg.insertEdge(3,4,45);
    dg.insertEdge(3,4,110);
    dg.insertEdge(4,2,30);
    dg.insertEdge(4,4,50);

    dg.print();

    return 0;
}