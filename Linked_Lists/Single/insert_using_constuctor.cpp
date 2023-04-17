#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    // Constructor
    Node(int val){
        data=val;
        next=NULL;
    }
};

void add_at_end(Node *&ref, int new_data){

    // allocate new node    
    Node *new_node=new Node(new_data);

    // add data and point list to null as it is the last list
    new_node -> data = new_data;
    new_node -> next = NULL;

    // if list is empty make new_node as head
    if(ref == NULL){
        ref = new_node;
        return;
    }

    // else traverse the list to find last
    Node *last=ref;
    while(last->next != NULL){
        last=last->next;
    }
    last->next=new_node;
    return;

}

void add_at_front(Node *&ref, int new_data){

    Node *new_node=new Node(new_data);

    // point the new node to where the head was pointing
    new_node -> next = ref;
    // make the head point to new node
    ref=new_node;
}

void add_after_node(Node *prev_node,int new_data){
    // check if given node is NULL
    if(prev_node == NULL){
        cout<<"Given node cannot be null";
        return;
    }
    Node * new_node= new Node(new_data);
    new_node -> data =new_data;
    new_node -> next =prev_node -> next;
    prev_node->next=new_node;
}

void add_at_index(Node *ref, int new_data, int index){
    Node *new_node =new Node(new_data);
    Node *new_ref =ref;

    int i=0;
    while(i!=index-1){
        new_ref=new_ref->next;
        i++;
    }
    new_node->data=new_data;
    new_node->next=new_ref->next;
    new_ref->next=new_node;
}

void print(Node *& node){
    Node *temp=node;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

int main(){

    Node *head=new Node(1);
    // linked list with 1 node
    add_at_front(head,7);
    // 7->1->NULL
    add_at_end(head,5);
    // 7->1->5->NULL
    add_at_end(head,10);
    // 7->1->5->10->NULL
    add_after_node(head->next,4);
    // 7->1->4->5->10->NULL;
    add_at_index(head,8,2);
    // 7->1->8->4->5->10->NULL;
    print(head);
    return 0;
}