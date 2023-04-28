#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next,*prev;

    Node(int val){
        data=val;
        next=prev=NULL;
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

void add_at_index(Node *&node,int new_data,int index){
    if(index==1){
        add_at_front(node,new_data);
        return;
    }
    Node *temp=new Node(new_data);
    int i=1;
    Node *trav=node;
    while(i!=index){
        trav=trav->next;
        i++;
    }
    temp->next=trav->next;
    temp->prev=trav;
    trav->next->prev=temp;
    trav->next=temp;

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

int main(){
    Node *tail=NULL;

    add_at_front(tail,5);
    add_at_front(tail,8);
    add_at_front(tail,7);
    // Forward
    // 7<->8<->5<->7
    // Backward
    // 5<->8<->7<->5


    add_at_index(tail,10,2);
    // Forward
    // 7<->10<->8<->5<->7
    // Backward
    // 5<->8<->10<->7<->5
    print(tail);
}

