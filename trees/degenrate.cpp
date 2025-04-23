#include<iostream>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int val):val(val){}
};

TreeNode* createNode(int val){
    return new TreeNode(val);
}

void insert(TreeNode*& root,int val,bool skewDirection){
    TreeNode* node = createNode(val);
    if(root == nullptr){
        root = node;
        return;
    }

    TreeNode* curr = root;
    if(skewDirection == 0){
        while(curr->left != nullptr){
            curr = curr->left;
        }
        curr->left = node;
        cout << "Successfully inserted in left" << endl;
        return;
    }
    else{
        while(curr->right != nullptr){
            curr = curr->right;
        }
        curr->right = node;
        cout << "Successfully inserted in right" << endl;
        return;
    }
}

void print(TreeNode* root,int skewedDir){
    TreeNode* curr = root;
    if(skewedDir == 0){
        while(curr != nullptr){
            cout << curr->val <<" ";
            curr = curr->left;
        }
    }
    else{
        while(curr != nullptr){
            cout << curr->val <<" ";
            curr = curr->right;
        }
    }
}

int main(){

    TreeNode* root = nullptr;
    // trying left skewed -> i.e., each child node is present to the left of the parent node / only a left pointered subtree forming like a linkedlist
    insert(root,10,0);
    insert(root,20,0);
    insert(root,30,0);
    insert(root,40,0);
    insert(root,50,0);

    // right skewed
    insert(root,30,1);
    insert(root,100,1);
    insert(root,400,1);
    insert(root,230,1);

    print(root,1);
    return 0;


}