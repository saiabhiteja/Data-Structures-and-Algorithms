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
void preorder_traversal(node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<"->"<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
    
    
}
vector<int>  print_itretative_preoder(node * root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    stack<node*>st;
    
    st.push(root);
    while(st.size()!=0){
        node* t = st.top();
        ans.push_back(t->data);
        st.pop();
        if(t->right){
            st.push(t->right);
        }
        if(t->left){
            st.push(t->left);
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

    //postorder
    preorder_traversal(root);
    cout<<endl ;
    vector<int> ans = print_itretative_preoder(root);
    for(auto it: ans){
        cout<<it<<" ";
    }

    return 0;
}