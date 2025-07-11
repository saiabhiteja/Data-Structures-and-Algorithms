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
node* lca(node* root,int p,int q){
    //base
    if(root == NULL ){
        return root;
    }
    if( root->data == p || root->data == q){
        return root;
    }
    //hypothesis
    node* left = lca(root->left,p,q);
    node* right = lca(root->right,p,q);

    //induce
    if(left == NULL){
        return right;
    }
    else if(right == NULL){
        return left;
    }
    else{
        return root ;
    }
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

    node* lcan = lca(root,25,35);
    cout<<lcan->data<<endl ;
   

    return 0;
}