#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *next;
};


struct Node* create(int value){
    struct Node *node = new Node;

    node->val = value;
    node->next = nullptr;
    
    return node;
}

void add(int value,Node*& head){
    Node* new_node = create(value);
    if(head == nullptr){
        head = new_node;
        head->next = nullptr;
        return;
    }
    if(head->next == nullptr){
        head->next = new_node;
        return;
    }

    Node* curr = head;
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = new_node;
    cout<<"Node added successfully"<<endl;
}



void display(Node* head){
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* curr = head;
    while(curr != nullptr){
        cout << curr->val<<" ";
        curr = curr->next;
    }
}


void remove(Node*& head,int pos){
    Node* curr = head;
    Node* prev = head;

    if(pos < 0){
        cerr<<"Invalid pos"<<endl;
        return;
    }

    if(pos == 0){
        Node* temp = head;
        head = temp->next;
        delete(temp);
    }
    int key=0;
    while(curr->next != nullptr && key != pos){
        ++key;
        if(key == pos){
            prev->next = curr->next;
            cout<<"Removed Node of value:"<<curr->val<<endl;
            delete(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    cerr<<"Index out of bounds"<<endl;

}









int main(){
    Node* head = nullptr;
    add(10,head);
    add(20,head);
    add(30,head);
    remove(head,0);
    display(head);
    return 0;
}