#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    // constructor
    Node(int val){
        data=val;
        next=prev=NULL;
    }
};

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

void add_at_front(Node *&ref,int new_data){
    Node *new_node=new Node(new_data);
    
    new_node ->next = ref;
    new_node ->prev=NULL;

    if(ref !=NULL)
    ref->prev=new_node;

    ref=new_node;
}

void add_at_index(Node *&head,int new_data,int index){
    if(index==1){
        add_at_front(head,new_data);
        return;
    }
    Node *cur=head,*last;
    int i=1;
    while(i!=index){
        last=cur;
        cur=cur->next;
        i++;
    }
    Node *temp=new Node(new_data);
    temp->prev=last;
    temp->next=last->next;
    last->next=temp;
    cur->prev=temp;
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

    Node *head=new Node(1);

    add_at_front(head,10);
    // 10<->1<->NULL
    add_at_end(head,5);
    // 10<->1<->5<->NULL
    add_at_index(head,7,2);
    // 10<->7<->1<->5<->NULL

    print(head);
    return 0;
}