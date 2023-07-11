#include<bits/stdc++.h>

using namespace std;

#define ll long long int 

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

ll height(Node *root){

    if(!root) return 0;

    ll left = 1+ height(root->left);
    ll right = 1+ height(root->right);

    return max(left,right);
}

int main(){

    return 0;

}