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
void inorder_traversal(node* root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root->left);
    cout<<root->data<<"->"<<" ";
    inorder_traversal(root->right);
}

bool isleaf(node* root){
    return ((root) && !(root->left) && !(root->right));
}
void solve(node* root1,node* root2){
    if(root1 == NULL || isleaf(root1)){
        return;
    }
    if(root1->left){
        root2->right = new node(root1->left->data) ;
    }
    if(root1->right){
        root2->left = new node(root1->right->data);
    }
    solve(root1->left,root2->right);
    solve(root1->right,root2->left);
    return;
}
node* create_mirror_tree(node* root ){
    if(root == NULL){
        return NULL;
    }
    node* root2 = new node(root->data);
    solve(root,root2);
    return root2;
}

void solve_2(node* root){
    if(root == nullptr || isleaf(root)){
        return;
    }
    node* temp = root->right ;
    root->right = root->left ;
    root->left = temp ;
    solve_2(root->right);
    solve_2(root->left);
    return;
}

node* mirror_the_given(node* root){
    if(root == nullptr){
        return nullptr;
    }
    //modifying the same tree
    solve_2(root);
    return root;
}

 void mirror(node* root) {
        // code here
        if(root==NULL)
        return ;
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            node* t = q.front();
            q.pop();
            swap(t->left,t->right);
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            
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

    node* root2 = create_mirror_tree(root);

    inorder_traversal(root);
    cout<<endl;
    inorder_traversal(root2);
    cout<<endl;
    root = mirror_the_given(root);
    inorder_traversal(root);

    

   

    return 0;
}