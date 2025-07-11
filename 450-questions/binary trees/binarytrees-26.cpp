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
    void solve(node* root,int level,map<int, priority_queue<int> >& mp,int& max_level,int sum){
        if(root == NULL){
            return;
        }
        sum = sum + root->data;
        if(isleaf(root)){
            //getting maximum level
            max_level = max(max_level,level);
            mp[level].push(sum);
            return;
        }
        solve(root->left,level+1,mp,max_level,sum);
        solve(root->right,level+1,mp,max_level,sum);
        sum = sum-root->data;
        return;
        
    }
    
    int sumOfLongRootToLeafPath(node *root)
    {
        if(root == NULL){
            return 0;
        }
        //using priority queue for getting maximum in same level 
        map<int, priority_queue<int> > mp;
        int max_level = 0;
        solve(root,1,mp,max_level,0);
        return(mp[max_level].top());
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

   cout<<sumOfLongRootToLeafPath(root);

    return 0;
}