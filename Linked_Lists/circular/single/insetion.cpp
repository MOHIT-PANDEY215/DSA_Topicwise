#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

void add_at_front(Node *&node,int new_data){
    Node *newNode=new Node(new_data);

    if(node==NULL){
        node=newNode;
        node->next=node;
    }
    else{
    newNode->next=node->next;
    node->next=newNode;
    }
}

void add_at_index(Node *&node,int new_data,int index){
    if(index==1){
        add_at_front(node,new_data);
        return;
    }
    Node *newNode=new Node(new_data);
    Node *temp=node;
    int i=1;
    while(i!=index){
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void print(Node *&node){
    Node *temp=node->next;
    while(temp!=node){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<"->"<<temp->next->data;

}

int main(){
    Node *tail=NULL;


    add_at_front(tail,5);
    add_at_front(tail,6);
    add_at_front(tail,7);
    // 7->6->5->7

    add_at_index(tail,8,2);
    // 7->8->6->5->7
    add_at_index(tail,9,4);
    // 7->8->6->9->5->7
    print(tail);
}