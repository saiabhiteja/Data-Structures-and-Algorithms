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
    kth largest element 
    -> we can store inorder and find kth element from last

    -> reverse inorder
*/
void solve(node* root,int& k,int& ans){
        if(root == nullptr){
            return;
        }
        solve(root->right,k,ans);
        k--;
        if(k == 0){
            ans = root->data;
        }
        solve(root->left,k,ans);
    }

    int kthLargest(node *root, int K)
    {
        if(root == nullptr){
            return 0;
        }
        int ans = 0;
        solve(root,K,ans);
        return ans;
        /*
        Time : O(N)
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
    cout<<endl;
    cout<<kthLargest(root,3)<<endl;

   

    return 0;
}