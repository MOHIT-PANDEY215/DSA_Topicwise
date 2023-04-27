#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node * prev;
    Node(int d){
        data=d;
        next=prev=NULL;
    }
    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
            this->prev=NULL;
        }
    }
};

void delete_at_front(Node *&node){
    Node *newNode=node;
    node=node->next;
    node->prev=NULL;
    newNode->prev=newNode->next=NULL;
    delete newNode;
}

void delete_at_index(Node *&node,int index){
    if(index==1){
        delete_at_front(node);
        return;
    }
    Node *newNode=node,*last;
    int i=1;
    while(i!=index){
        last=newNode;
        newNode=newNode->next;
        i++;
    }
    last->next=newNode->next;
    newNode->next->prev=last;
    newNode->next=NULL;
    newNode->prev=NULL;
    delete newNode;

}

void add_at_end(Node *&ref,int new_data){
    Node *new_node=new Node(new_data);
    
    new_node ->next=NULL;

    if(ref==NULL){
        new_node->prev =NULL;
        ref=new_node;
        return;
    }
    Node *last=ref;
    while(last->next!=NULL){
        last=last->next;
    }

    last->next=new_node;
    new_node->prev=last;
}

void print(Node *&node){
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
    Node *head=new Node(2);

    add_at_end(head,3);
    add_at_end(head,5);
    add_at_end(head,1);
    add_at_end(head,6);
    // Forward print
    // 2<->3<->5<->1<->6<->NULL
    // Backward print
    // 6<->1<->5<->3<->2<->NULL

    delete_at_index(head,2);
    print(head);


    return 0;
}