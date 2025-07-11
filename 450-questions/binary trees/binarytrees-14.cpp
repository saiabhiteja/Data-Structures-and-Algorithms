#include <iostream>
#include "bits/stdc++.h"
using namespace std;
struct node {
    int data;
    struct node *left=nullptr, *right=nullptr;

    node(int x){
        data = x;
    }
};
void level_order(node* root){
    queue<node*> q;
    q.push(root);
    while(q.size()!=0){
        node* t = q.front();
        q.pop();
        cout<<t->data<<" ";
        if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
        }
    }
}
int height(node* root){
    //base
    if(root == NULL){
        return 0;
    }
    //hypothesis
    int left = height(root->left);
    int right = height(root->right);
    //induction
    return (max(left,right)+1) ;
}

bool is_balanced(node* root){
    //o(n^2)
    //recursion
    //brute-force

    if(root==NULL){
        return true;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh)>1){
        return false;
    }
    bool r = is_balanced(root->right);
    bool l = is_balanced(root->left);
    if(!(r || l)){
        return false;
    }
    return true;
}

int is_balance(node* root){
    //same as height of tree
    //we find wether tree is balanced or not
    //base
    if(root == NULL){
        return 0;
    }
    //hypothesis
    int lh = is_balance(root->left);
    int rh = is_balance(root->right);
    if(lh==-1 || rh == -1){
        return -1;
    }
    if(abs(lh-rh)>1){
        return -1;
    }
    //induction
    return (1+max(lh,rh));
    //finding if balanced or not 
    //o(n) because of recursive traversal
    //if height == -1 -> tree is not balanced
}
bool balanced(node* root){
    return is_balance(root)!=-1 ;
}


int main(){
    //creating tree;
    node* root = new node(5);
    root->left = new node(10);
    root->right = new node(12);
    root->right->right = new node(20);
    root->left->left = new node(25);
    root->left->right = new node(35);
    root->right->left = new node(40);

    //balanced tree
    if(balanced(root)){
        cout<<"Tree is balanced"<<endl;
        cout<<"height :"<<is_balance(root)<<endl;
    }
    else{
        cout<<"Tree is Not balanced"<<endl;
    }

   

    return 0;
}