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
int height(node* root){
    //base
    if(root == NULL){
        return 0;
    }
    //hypothesis
    int left = height(root->left);
    int right = height(root->right);
    //induction
    return (max(left,right)+1) ;
}
//diameter : The longest path between two nodes
//diameter may or may not pass through the root
int diameter(node* root){
    //base
    if(root == NULL){
        return 0;
    }
    //hypo
    int left = height(root->left);
    int right = height(root->right);
    int tot = left+right+1;
    int left_d = diameter(root->left);
    int right_d = diameter(root->right);
    //induction
    
    return (max(tot,max(left_d,right_d)));

}

int diameter_without_h(node* root,int* height){
    //s:o(N)
    //t:o(N)
    //base
    if(root == NULL){
        *height = 0;
        return 0;
    }
    //hypothesis
    int lh = 0,rh = 0;
    int left = diameter_without_h(root->left,&lh);
    int right = diameter_without_h(root->right,&rh) ;
    //induction
    *height = max(lh,rh)+1;
    return (max((lh+rh+1),max(left,right)));
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

    //diameter
    cout<<diameter(root)<<endl;
    int height = 0;
    cout<<diameter_without_h(root,&height);
    

   

    return 0;
}