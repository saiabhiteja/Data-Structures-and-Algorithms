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
void postorder_traversal(node* root){
    if(root == NULL){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout<<root->data<<"->"<<" ";
    
}
void print_itretative_postoder(node * root){
    //using two stacks
    stack<node*>st1,st2;
    st1.push(root);
    while(st1.size()!=0){
        node* t = st1.top();
        st1.pop();
        st2.push(t);
        if(t->left){
            st1.push(t->left) ;
        }
        if(t->right){
            st1.push(t->right);
        }
    }
    while(st2.size()!=0){
        node* t = st2.top();
        st2.pop() ;
        cout<<t->data<<" ";
    }

}

vector<int> print_itretative_postoder_2(node * root){
    //using one stacks
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    stack<node*>st1;
    st1.push(root);
    while(st1.size()!=0){
        node* t = st1.top();
        st1.pop();
        ans.push_back(t->data);
        if(t->left){
            st1.push(t->left) ;
        }
        if(t->right){
            st1.push(t->right);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans ;
    

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

    //postorder
    postorder_traversal(root);
    cout<<endl;
    print_itretative_postoder(root);
    cout<<endl;
    vector<int> ans = print_itretative_postoder_2(root);
    for(auto it:ans){
        cout<<it<<" ";
    }

    return 0;
}