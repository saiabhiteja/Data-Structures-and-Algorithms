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
bool isleaf(node* root){
        return((root->left == NULL) && (root->right == NULL) && (root));
    }
    
    int solve(node* root){
        //base
        if(root == NULL){
            return 0;
        }
        if(isleaf(root)){
            return (root->data);
        }
        //hypothesis
        int left = solve(root->left);
        int right = solve(root->right);
        //induction
        if(left == -1 || right == -1){
            return(-1);
        }
        if(root->data == (left+right)){
            root->data = root->data + left+right ;
            return(root->data);
        }
        return (-1);
        
    }
    bool isSumTree(node* root)
    {
        
        return (solve(root)!=-1) ;
         
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

    if(isSumTree(root)){
        cout<<"This is a sum tree";
    }
    else{
        cout<<"Not a sum tree";
    }

   

    return 0;
}