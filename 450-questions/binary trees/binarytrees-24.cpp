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

bool isleaf(node* root){
      return ((root) && !(root->left) && !(root->right));
  }
  bool isidentical(node* root1,node* root2){
      if(root1 == nullptr || root2 == nullptr){
          return (root1 == root2);
      }
      if(root1->data != root2->data){
          return false;
      }
      return ((isidentical(root1->left,root2->left)) &&
      (isidentical(root1->right,root2->right))) ;
  }
 
    
    int dupSub(node *root) {
         if(!root){
             return 0;
         }
         map<char,vector<node*>> mp;
         queue<node*> q;
         q.push(root);
         while(q.size()!=0){
             node* temp = q.front();
             q.pop();
             if(!(isleaf(temp))){
                 mp[temp->data].push_back(temp);
             }
             if(temp->left){
                 q.push(temp->left);
             }
             if(temp->right){
                 q.push(temp->right);
             }
         }
         
         for(auto i : mp){
             if(i.second.size()>=2){
                 vector<node*> temp = i.second ;
                 int n = temp.size();
                 for(int i = 0;i<n-1;i++){
                     for(int j = i+1;j<n;j++){
                         if(isidentical(temp[i],temp[j])){
                             return 1;
                         }
                     }
                 }
                 
             }
         }
         return 0;
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

    cout<<dupSub(root)<<endl;

   

    return 0;
}