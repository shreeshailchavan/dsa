#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev = nullptr;
    Node* next = nullptr;
};

Node* create_node(int val)
{
    Node* node = new Node;
    node->data = val;
    node->prev ;
    node->next ;
    return node;
}


void add(Node*& head,int val){
    Node* new_node = create_node(val);
    if(head == nullptr){
        head = new_node;
        return;
    }

    Node* curr = head;
    while(curr->next != nullptr){
        curr = curr->next;
    }

    new_node->prev = curr;
    curr->next = new_node;
    new_node->next = nullptr;
    cout << "Node -> "<<val<<" added successfully" << endl;
}

void remove(Node*& head,int pos){
    if(pos <= 0){
        cerr<<"Pos should be > 0" << endl;
        return;
    }
    Node* curr = head;
    Node * prev = head;
    long long key = 0;
    while(curr->next != nullptr){
        ++key;
        if(key == pos){
            prev->next = curr->next;
            curr->next->prev = prev;
            if(key == 1)
                head = curr->next;
            delete(curr);
            cout << "Node removed successfully!" << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Position not found" <<endl;
}

void display(Node* head){
    if(head == nullptr){
        cerr<<"Empty LL" <<endl;
        return;

    }
    Node* curr = head;
    while(curr->next != nullptr){
        cout << curr->data << endl;
        curr = curr->next;
    }
}



int main(){
    Node* head = nullptr;
    add(head,10);
    add(head,20);
    add(head,30);
    add(head,40);
    display(head);

    remove(head,1);
    display(head);
    return 0;
}