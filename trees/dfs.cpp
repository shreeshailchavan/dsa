#include<bits/stdc++.h>
using namespace std;

// dfs ->
    // 1. Inorder (Left , Root, Right)
    // 2. Preorder (Root , Left, Right)
    // 3. PostOrder (Left,Right,Root)


class Node{
    public:
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
    public:    
        Node(int data):data(data){}
        
};

Node* create_node(int val){
    Node* node = new Node(val);
    return node;
}

void add_node(Node*& root,int val){
    Node* new_node = create_node(val);
    if(root == nullptr){
        root = new_node;
        return;
    }
    Node* curr = root;
    while(true){
        if(curr->data < val){
            if(curr->right == nullptr){
                curr->right = new_node;
                return;
            }
            curr = curr->right;
        }
        else{
            if(curr->left == nullptr){
                curr->left = new_node;
                return;
            }
            curr = curr->left;
        }
    }
}

void inorder(Node* root){
    if(root == nullptr)
        return;
    inorder(root->left);
    cout<<root->data<< "    ";
    inorder(root->right);
}



int main(){

    Node* root = nullptr;
    add_node(root,10);
    add_node(root,20);
    add_node(root,5);
    add_node(root,40);
    add_node(root,2);
    inorder(root);
    return 0;
}