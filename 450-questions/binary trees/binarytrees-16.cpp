//anti clockwise direction
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
    return ((root->left == NULL) && (root->right == NULL));
}
void addleft(node* root,vector<int>& res){
    node* curr = root->left;
    while(curr){
        if(!(isleaf(curr))){
            res.push_back(curr->data);
        }
        if(curr->left){
            curr = curr->left;
        }
        else{
            curr = curr->right ;
        }
    }

}
void addright(node* root,vector<int>& res){
    node* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!(isleaf(curr))){
            temp.push_back(curr->data);
        }
        if(curr->right){
            curr = curr->right;
        }
        else{
            curr = curr->left ;
        }
    }
    for(int j = temp.size()-1;j>=0;j--){
        res.push_back(temp[j]);
    }
    
}
void addleaves(node* root,vector<int>& res){
    if(isleaf(root)){
        res.push_back(root->data);
    }
    if(root->left){
        addleaves(root->left,res);
    }
    if(root->right){
        addleaves(root->right,res);
    }

    
}
vector<int> boundarytraversal(node* root){
    vector<int> res;
    if(root == NULL){
        return res;
    }
    res.push_back(root->data);
    addleft(root,res);
    addleaves(root,res);
    addright(root,res);
    return res ;
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
    
    //anti-clockwise traversal
    vector<int> t = boundarytraversal(root);
    for(int i = 0;i<t.size();i++){
        cout<<t[i]<<" ";
    }

   

    return 0;
}