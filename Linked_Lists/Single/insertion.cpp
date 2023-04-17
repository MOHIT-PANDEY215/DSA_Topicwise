#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
};

// using struct keyword

// struct Node{
//     int data;
//     struct Node *next;
// };

void add_at_end(Node **ref, int new_data){

    // allocate new node    
    Node *new_node=new Node();

    // add data and point list to null as it is the last list
    new_node -> data = new_data;
    new_node -> next = NULL;

    // if list is empty make new_node as head
    if(*ref == NULL){
        *ref = new_node;
        return;
    }

    // else traverse the list to find last
    Node *last=*ref;
    while(last->next != NULL){
        last=last->next;
    }
    last->next=new_node;
    return;

}

void add_at_front(Node **ref, int new_data){

    Node *new_node=new Node();
    new_node -> data = new_data;
    // point the new node to where the head was pointing
    new_node -> next = *ref;
    // make the head point to new node
    *ref=new_node;
}

void add_after_node(Node *prev_node,int new_data){
    // check if given node is NULL
    if(prev_node == NULL){
        cout<<"Given node cannot be null";
        return;
    }
    Node * new_node= new Node();
    new_node -> data =new_data;
    new_node -> next =prev_node -> next;
    prev_node->next=new_node;
}

void add_at_index(Node *ref, int new_data, int index){
    Node *new_node =new Node();
    Node *new_ref =ref;

    int i=1;
    while(i!=index-1){
        new_ref=new_ref->next;
        i++;
    }
    new_node->data=new_data;
    new_node->next=new_ref->next;
    new_ref->next=new_node;
}

void print(Node *node){
    while(node!=NULL){
        cout<<node->data<<"->";
        node=node->next;
    }
    cout<<"NULL";
}

int main(){

    Node *head=NULL;
    // Empty list
    add_at_end(&head,5);
    // 5->NULL
    add_at_front(&head,7);
    // 7->5->NULL
    add_at_end(&head,10);
    // 7->5->10->NULL
    add_after_node(head->next,4);
    // 7->5->4->10->NULL;
    add_at_index(head,8,2);
    // 7->8->5->4->10->NULL;
    print(head);
    return 0;
}