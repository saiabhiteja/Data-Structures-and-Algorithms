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

void helper(node* root,int diagonal,map<int,vector<int>>& ans){
    if(root == nullptr){
        return ;
    }
    ans[diagonal].push_back(root->data);
    helper(root->left,diagonal+1,ans);
    helper(root->right,diagonal,ans);
}

void  diagnonal_tr(node* root){
    map <int,vector<int>> ans;
    
    helper(root,0,ans);
    for (auto it : ans)
    {
        vector<int> v=it.second;
        for(auto it:v)
          cout<<it<<" ";
        cout<<endl;
    }
}

void diagonal_traversal(node* root){
    //Time: O(N)
    //space : O(N)
    if(root == nullptr){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(q.size()!=0){
        int s = q.size();
        for(int i = 0;i<s;i++){
            node* temp = q.front();
            q.pop();
            while(temp){
                cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                temp = temp->right ;
            }
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

    diagonal_traversal(root);
    cout<<endl;
    diagnonal_tr(root);

   

    return 0;
}