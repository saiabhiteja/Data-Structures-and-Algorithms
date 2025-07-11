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
    return (root && !root->left && !root->right) ;
}

//helper function 
int helper(node* root, int & ans){
    if(!root){
        return 0;
    }
    int le = helper(root->left,ans);
    int ri = helper(root->right,ans);
    int curr = root->data+le+ri ;
    ans = max(ans,curr) ;

    return (curr) ;
}

int max_sub_tree(node* root){
    //function for finding the maximuim subtree
    if(!root){
        return 0;
    }
    int ans = 0;
    //using helper function 
    helper(root,ans);
    return ans ;
}
int main(){
    //creating tree;
    node* root = new node(1);

    root->left = new node(-2);
    root->right = new node(3);
    
    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(-6);
    root->right->right = new node(2);

    //level order
    level_order(root);
    cout<<endl ;
    cout<<"maximum sub tree sum : "<<max_sub_tree(root)<<endl ;


   

    return 0;
}