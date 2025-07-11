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
 int clsum(node * root)
   {
       if(root->left == NULL && root->right == NULL)
       {
           int x= root->data;
           root->data = 0;
           return x;
       }
       else
       {
           int lef=0;
           int rig=0;
           if(root->left)
           lef = clsum(root->left);
           if(root->right)
           rig = clsum(root->right);
           
           int x = root->data;
           root->data = lef+rig;
           x = x+root->data;
           return x;
       }
   }
void toSumTree(node *root)
{
    clsum(root);
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
    level_order(root);
    toSumTree(root);
    cout<<" After changing to tosumtree"<<endl;
    level_order(root);

    

   

    return 0;
}