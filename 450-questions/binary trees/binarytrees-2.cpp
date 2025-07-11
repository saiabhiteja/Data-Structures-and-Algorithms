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



vector<int> level_order(node* root){
    vector<int> ans;
    if(!root){
        return ans;
    }
    queue<node*> q;
    q.push(root);
    while(q.size()!=0){
        node* t = q.front();
        q.pop();
        ans.push_back(t->data);
        if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
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

    //level order
    vector<int> ans = level_order(root);
    for(auto it:ans){
        cout<<it<<" ";
    }

   

    return 0;
}