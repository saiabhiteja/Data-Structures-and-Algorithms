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
    finding Lca of two nodes
*/
node* LCA(node *root, int n1, int n2)
{
   while (root) {
            if (n1 < root->data && n2 < root->data)
            root = root->left;
            
            else if (n1 > root->data && n2 > root->data) 
            root = root->right;
            
            //when both are at different sides
            //when one value itself equal to given data
            else 
            return root;
        }
        //if not found 
        return root;
        /*
        Time : O(H)
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
    cout<<endl ;
    node* ans = LCA(root,20,14);
    cout<<ans->data<<endl;

   

    return 0;
}