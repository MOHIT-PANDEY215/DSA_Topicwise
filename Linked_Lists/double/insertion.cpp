#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
};

void add_at_end(Node **ref,int new_data){
    Node *new_node=new Node();
    new_node -> data =new_data;
    new_node ->next=NULL;

    if(*ref==NULL){
        new_node->prev =NULL;
        *ref=new_node;
        return;
    }
    Node *last =new Node();
    while(last->next!=NULL){
        last=last->next;
    }

    last->next=new_node;
    new_node->prev=last;
    return;
}

void add_at_front(Node **ref,int new_data){
    Node *new_node=new Node();
    new_node ->data =new_data;
    new_node ->next = *ref;
    new_node ->prev=NULL;

    if(*ref !=NULL)
    (*ref)->prev=new_node;

    *ref=new_node;
}

void print(Node *node){
    // Forward print
    cout<<"Forward print\n";
    Node *last; //to store last node of the list
    while(node!=NULL){
        cout<<node->data<<"<->";
        last=node;
        node=node->next;
    }
    cout<<"NULL\n";

    // Backward print
    cout<<"Backward print\n";
    while(last!=NULL){
        cout<<last->data<<"<->";
        last=last->prev;
    }
    cout<<"NULL\n";
}

int main(){

    Node *head=NULL;
    add_at_end(&head,5);
    add_at_front(&head,10);

    print(head);
    return 0;
}