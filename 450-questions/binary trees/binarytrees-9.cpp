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

//left veiw
//using level order
void left_veiw(node* root){
    queue<node*> q;
    q.push(root);
    while(q.size()!=0){
        int count = q.size();
        for(int i = 0;i<count;i++){
            node* temp = q.front();
            q.pop();
            if(i==0){
                cout<<temp->data<<" ";
            }
            
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

//using recursion
//pre order = node,left,right
//so we recursively call using root and level
//reducing space complexity
//time : o(N)
//space : o(h)
void leftveiw(node* root,int level,vector<int>& ans){
    if(root == NULL){
        return ;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
        leftveiw(root->left,level+1,ans);
        leftveiw(root->right,level+1,ans);
    
   
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
    left_veiw(root);
    cout<<endl;
    vector<int> ans ;
    leftveiw(root,0,ans);
    for(auto it: ans){
        cout<<it<<" ";
    }

   

    return 0;
}