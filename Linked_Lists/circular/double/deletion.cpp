#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next,*prev;

    Node(int val){
        data=val;
        next=NULL;
    }

    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
            this->prev=NULL;
        }
    }
};

void add_at_front(Node *&node,int new_data){
    Node *temp=new Node(new_data);

    if(node==NULL){
        node=temp;
        node->next=node->prev=node;
    }
    else{
        temp->next=node->next;
        temp->prev=node;
        node->next=temp;
        temp->next->prev=temp;
    }
}


void print(Node *&node){
    Node *temp=node->next;
    cout<<"Forward\n";
    while(temp!=node){
        cout<<temp->data<<"<->";
        temp=temp->next;
    }
    cout<<temp->data<<"<->"<<temp->next->data;
    cout<<"\nBackward\n";
    Node *last=node;
    while(last!=node->next){
        cout<<last->data<<"<->";
        last=last->prev;
    }
    cout<<last->data<<"<->"<<last->prev->data;
}

void delete_at_index(Node *&node,int index){
    Node *temp=node->next;
    if(index==1){
        node->next=node->next->next;
        node->next->prev=node;
        temp->next=temp->prev=NULL;
        delete temp;
    }
    else{
        int i=1;
        Node *last=temp;
        while(i!=index){
            last=temp;
            temp=temp->next;
            i++;
        }
        last->next=temp->next;
        last->next->prev=last;
        temp->next=temp->prev=NULL;
        delete temp;

    }
}

int main(){
    Node *tail=NULL;

    add_at_front(tail,5);
    add_at_front(tail,8);
    add_at_front(tail,7);
    // Forward
    // 7<->8<->5<->7
    // Backward
    // 5<->8<->7<->5

    delete_at_index(tail,2);
    // Forward
    // 7<->5<->7
    // Backward
    // 5<->7<->5
    print(tail);
}