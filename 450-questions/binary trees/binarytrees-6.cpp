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
vector<int> inorder_traversal_2(node* root){
    //using stack
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    stack<node*> st;
    node* t = root;
    while(t || st.size()!=0){
        if(t!=NULL){
            st.push(t);
            t = t->left;
        }
        else{
            t = st.top();
            ans.push_back(t->data);
            st.pop();
            t = t->right;
        }

    }
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

    //inorder traversal
    inorder_traversal(root);
    cout<<endl;
    vector<int> ans = inorder_traversal_2(root);
    for(auto it: ans){
        cout<<it<<" ";
    }


    return 0;
}