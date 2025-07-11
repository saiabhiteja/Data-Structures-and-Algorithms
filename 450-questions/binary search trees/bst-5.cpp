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
/*
    checking wether given tree is valid bst or not
*/
bool helper(node* root,int max_value,int min_value){
    if(!root) return true ;
    if(root->data<min_value || root->data>max_value){
        return false ;
    }
    return helper(root->left,root->data,min_value) && 
        helper(root->right,max_value,root->data) ;
}
bool isvalid (node* root){
    return helper(root,INT_MAX,INT_MIN) ;
    /*
    Time : O(N)
    Space : O(1)
    */
}
int main(){
    //creating tree;
    node* root = new node(15);
    root->left = new node(13);
    root->right = new node(20);
    root->right->right = new node(24);
    root->left->left = new node(12);
    root->left->right = new node(14);
    root->right->left = new node(16);

    //display
    level_order(root);

    if(isvalid(root)){
        cout<<"given tree is bst"<<endl;
    }
    else{
        cout<<"Not a Bst"<<endl;
    }

   

    return 0;
}