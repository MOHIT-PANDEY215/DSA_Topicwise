#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data=val;
        next=NULL;
    }

    ~Node(){
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
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

void print(Node *&node){
    Node *temp=node->next;
    while(temp!=node){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<"->"<<temp->next->data;

}

void delete_at_index(Node *&node,int index){
    Node *temp=node->next;
    if(index==1){
        node->next=node->next->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node *last=temp;
        int i=1;
        while(i!=index){
            last=temp;
            temp=temp->next;
            i++;
        }
        last->next=temp->next;
        temp->next=NULL;
        delete temp;
        
    }
    
 
}

int main(){
    Node *tail=NULL;

    add_at_front(tail,5);
    add_at_front(tail,3);
    add_at_front(tail,8);
    add_at_front(tail,6);
    add_at_front(tail,4);
    // 4->6->8->3->5->4

    delete_at_index(tail,2);
    // 4->8->3->5->4

    print(tail);
}