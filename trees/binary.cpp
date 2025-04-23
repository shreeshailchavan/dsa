#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int data):val(data){}
};


Node* createNode(int val){
    Node* node = new Node(val);
    return node;
}

void insert(Node*& root,int val){
    Node* node = createNode(val);
    if(root == nullptr){
        root = node;
        return;
    }
    else{
        Node* curr = root;
        curr = node;
    }
}


void print(Node* root){
    if(root == nullptr)
        return;
    print(root->left);
    cout << root->val <<" ";
    print(root->right);

}

int main(){

    Node* root = nullptr;
    insert(root,10);
    insert(root->left,20);
    insert(root->right,30);
    insert(root->left->left,40);
    insert(root->left->right,50);

    print(root);
    return 0;
}