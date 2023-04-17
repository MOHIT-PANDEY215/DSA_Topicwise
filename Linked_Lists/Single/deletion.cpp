#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    // constructor
    Node(int val){
        data=val;
        next=NULL;
    }

    // destructor
    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
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

void print(Node *& node){
    Node *temp=node;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

void delete_index(Node *& node,int index){

    // start position
    if(index==1){
        Node *temp=node;
        node=node->next;
        temp->next=NULL;
        delete temp;
    }
    // any other position
    else{
        Node *cur=node;
        Node *prev;
        int i=1;
        while(i!=index){
            prev=cur;
            cur=cur->next;
            i++;
        }
        prev->next=cur->next;
        cur->next=NULL;
        delete cur;
    }
    
}

int main(){
    Node *head =new Node(1);
    
    add_at_end(head,5);
    add_at_end(head,8);
    add_at_end(head,45);
    // 1->5->8->45->NULL

    delete_index(head,2);
    // 1->8->45->NULL

    print(head);

    return 0;
}