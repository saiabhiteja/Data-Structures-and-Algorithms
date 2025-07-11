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
        return (root && (!root->left) && !(root->right));
    }
    void solve(node* root,set<int>& levels,int level){
        if(!root){
            return ;
        }
        if(isleaf(root)){
            levels.insert(level);
            return;
        }
        solve(root->left,levels,level+1);
        solve(root->right,levels,level+1);
    }
    bool check(node *root)
    {
        set<int> levels;
        solve(root,levels,1);
        if(levels.size()==1){
            return true;
        }
        else{
            return false;
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

    if(check(root)){
        cout<<" all leaf nodes are at same level";
    }
    else{
        cout<<"leave nodes are different level";
    }

   

    return 0;
}