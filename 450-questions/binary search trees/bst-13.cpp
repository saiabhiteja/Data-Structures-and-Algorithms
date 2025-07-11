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
Finding kth smallest element 
->inorder

*/
void solve(node* root,int& ans,int&k){
    if(root == nullptr){
        return;
    }
    solve(root->left,ans,k);
    k--;
    if(k == 0){
        ans = root->data;
    }
    solve(root->right,ans,k);
}

int KthSmallestElement(node* root, int k) {
    if(root == nullptr){
        return 0;
    }
    int ans = -1;
    solve(root,ans,k);
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
    cout<<endl ;
    cout<<KthSmallestElement(root,3)<<endl;

   

    return 0;
}