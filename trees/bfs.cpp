#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int data):data(data){}
};

Node* createNode(int data){
    Node* node = new Node(data);
    return node;
}

void addNode(Node*& root,int data){
    Node* node = createNode(data);
    if(root == nullptr){
        root = node;
        return;
    }
    Node* curr = root;
    while(true){
        if(curr->data < data){
            if(curr->right == nullptr){
                curr->right = node;
                return;
            }
            curr = curr->right;
        }
        else{
            if(curr->left == nullptr){
                curr->left = node;
                return;
            }
            curr = curr->left;
        }
    }
    
}


// level order traversal BFS
void levelOrderTraversal(Node* root,vector<vector<int>>& v,int index){
    if(root == nullptr)
        return;
    if(v.size() <= index){
        v.push_back({});
    }
    v[index].push_back(root->data);
    levelOrderTraversal(root->left,v,index+1);
    levelOrderTraversal(root->right,v,index+1);
}


vector<vector<int>> levelOrder(Node* root){
    vector<vector<int>> v;
    int index = 0;
    // perform level order traversal
    levelOrderTraversal(root,v,index);

    return v;
}

// dfs -> inorder
void inorder(Node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}


vector<vector<int>> inorderWithQueue(Node* root){
    vector<vector<int>> res;
    queue<Node*> q;
    q.push(root);
    int currentLevel = 0;
    while(!q.empty()){
        int len = q.size();
        res.push_back({});
        for(int i=0;i<len;i++){
            Node* node = q.front();
            q.pop();
            cout << "data->" << node->data<<"   ";
            res[currentLevel].push_back(node->data);

            if(node->left != nullptr){
                q.push(node->left);
            }

            if(node->right != nullptr){
                q.push(node->right);
            }
        }
        currentLevel++;
    }


    return res;


}

int main(){
    Node* root = nullptr;
    addNode(root,10);
    addNode(root,20);
    addNode(root,30);
    addNode(root,4);
    addNode(root,5);
    cout << "Inorder : " << endl;
    inorder(root);
    cout<<"Levelorder : " << endl;
    vector<vector<int>> res = levelOrder(root);
    for(auto& it:res){
        for(int i:it)
            cout<<i<<" ";
        cout<<endl;
    }

    // Inorder with queue
    vector<vector<int>> result = inorderWithQueue(root);
    for(auto it:result){
        cout<<"[";
        for(int i:it){
            cout<<i<<" ";
        }
        cout << "]"<<endl;
    }




    return 0;
}