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

node* search_2(node* root,int target){
    //base
    if(root == nullptr){
        return nullptr;
    }

    if(root->data == target){
        return root;
    }
    //hypothesis
    if(root->data > target){
        return search_2(root->left,target);
    }
    else{
        return search_2(root->right,target);
    }
}

bool search(node* root,int target){
    
    while(root!=nullptr){
        if(root->data == target){
            return true;
        }
        else if(root->data > target){
            root = root->left;
        }
        else{
            root = root->right ;
        }
    }
    return false;
}

node*insert_2(node*root ,int key){
    if(root == nullptr){
        return (new node(key));
    }
    if(root->data>key){
        root->right =  insert_2(root->left,key);
    }
    else{ 
       root->left =  insert_2(root->right,key);

    } 
    return root ;
}

node* insert(node* root,int key){
    //base
    if(root == nullptr){
        node*  new_root = new node(key) ;
        return new_root;
    }
    node* prev = nullptr;
    node* temp = root;
    while(temp !=nullptr){
        if(temp->data<key){
            prev = temp;
            temp = temp->left;
        }
        else{
            prev = temp;
            temp = temp->right;
        }
    }
    if(prev->data < key){
        prev->right = new node(key);
    }
    else{
        prev->left = new node(key);
    }

    return root;
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
    if(search(root,55)){
        cout<<"55 is prsent in bst";
    }
    else{
        cout<<"55 is not  present";
    }


    //search_2;
    node* find = search_2(root,12);
    if(find == nullptr){
        cout<<endl<<" 12  is not present";
    }
    else{
        cout<<endl<<"12 is present";
    }


    insert(root,48);
    cout<<endl<<"after insertion"<<endl;
    level_order(root);
   

    return 0;
}