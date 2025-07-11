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
    find a pair who sum to given value x
*/
bool search(node* root,int key){
    //function for searching an element in a tree
        while(root!=nullptr){
            if(root->data == key){
                return true;
            }
            else if(root->data<key){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return false;
    }
    
void traversal(node* root1,int x,node* root2,int& ans){
    //function for traversing one tree and searching value in other tree
        if(root1 == nullptr){
            return;
        }
        traversal(root1->left,x,root2,ans);
        if(search(root2,(x-root1->data))){
            ans++;
        }
        traversal(root1->right,x,root2,ans);
    }

int countPairs(node* root1, node* root2, int x)
    {
        int ans = 0;
        traversal(root1,x,root2,ans);
        return ans;
        /*
        Time : O(N*log(N))
        Space : O(1) //without recursive stack
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

    //tree-2
    node* root2 = new node(14);
    root2->left = new node(12);
    root2->right = new node(20);
    root2->right->right = new node(22);
    root2->left->left = new node(10);
    root2->left->right = new node(13);
    root2->right->left = new node(16);

    cout<<countPairs(root,root2,40)<<endl;

   

    return 0;
}