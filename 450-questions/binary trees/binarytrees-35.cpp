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
bool isIsomorphic(node *root1,node *root2)
    {
        //base
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1 == NULL || root2 ==NULL){
            return (root1==root2);
        }
        if(root1->data!=root2->data){
            return false;
        }  
return((isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right)) 
|| (isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left)));
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

    node* root2 = new node(5);
    root2->left = new node(10);
    root2->right = new node(12);
    root2->right->right = new node(20);
    root2->left->left = new node(25);
    root2->left->right = new node(35);
    root2->right->left = new node(40);

    if(isIsomorphic(root,root2)){
        cout<<" Both trees are Isomorphic";
    }
    else{
        cout<<"Trees are Not Isomorphic";
    }


   

    return 0;
}