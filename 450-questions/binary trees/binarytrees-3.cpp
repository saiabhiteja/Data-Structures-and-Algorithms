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

int height(struct node* root){
        if(root == NULL)
        {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return (max(left,right)+1);
        
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
    cout<<height(root)<<endl;

   

    return 0;
}