#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int E;
        vector<vector<pair<int,int>>> adjList;

    public:
        Graph(int E){
        this->E = E;
        adjList.resize(E+1);
    }

//  u-> node1 v -> node2 weight
    void insertEdge(int u,int v,int weight=1){
        // adding edge from u -> v
        adjList[u].push_back({v,weight});
    }
    void print(){
        int i=0;
        for(auto it:adjList){
            cout << "Edge " << i <<" -> [";
            for(auto v:it){
                cout << "{"<<v.first <<"," << v.second <<"},";
            }
            cout << "]"<<endl;
            i++;
        }
    }

};

int main(){
    Graph ug(5);
    ug.insertEdge(1,2,10);
    ug.insertEdge(1,4,20);
    ug.insertEdge(4,4,10);
    ug.insertEdge(3,2,40);

    ug.print();

    return 0;
}