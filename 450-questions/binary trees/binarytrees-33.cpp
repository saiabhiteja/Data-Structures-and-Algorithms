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
    Finding Kth ancestor
*/
node* parent_pointers(node* root,int key,unordered_map<node*,node*>& mp){
    if(!root) return root;
    queue<node*> q ;
    mp[root] = NULL ;
    node* ans = NULL ;
    q.push(root);
    while(q.size()!=0){
        node* temp = q.front() ;
        q.pop();
        if(temp->data == key){
            ans = temp;
        }
        if(temp->left){
            q.push(temp->left);
            mp[temp->left] = temp;
        }
        if(temp->right){
            q.push(temp->right);
            mp[temp->right] = temp ;
        }
    }
    return ans ;
    /*
    Time : O(N)
    space : O(N)
    */

}
int method_1(node* root,int key,int k){
    /* I will create parent pointer and rverse travesrs k times*/
    if(!root) return -1;
    unordered_map<node*,node*> mp ;
    node* req = parent_pointers(root,key,mp) ;
    if(!req) return -1;
    while(k){
        if(req == NULL){
            return -1;
        }
        req = mp[req] ;
        k--;
    }
    if(!req) return -1;
    return req->data ;

}


//2nd method
int helper(node* root,int key,int k,int& ans){
    if(!root || ans!= -1) return 0;

    int lef_val = helper(root->left,key,k,ans) ;
    int right_val = helper(root->right,key,k,ans);
    //cout<<lef_val<<" "<<right_val<<endl;


    if(root->data == key) return 1;

    
    if(lef_val == 0 && right_val == 0 ) return 0;

    int val = max(lef_val,right_val) ;
    //cout<<val<<endl;
    if(val == k){
        ans = root->data ;
    }
    //cout<<val<<endl;
    return val+1;
}
int method_2(node* root,int key,int k){
    if(!root)
     return -1;
     //cout<<root->data<<endl;
    int ans = -1;
    helper(root,20,2,ans);
    return ans ;
    /*
    Time : O(N)
    Space : O(N)
    */

}

//method3
void helper(node* root,int key,int k,vector<int> temp,int& ans,bool& nt){
    if(!root || ans!=-1||nt){
        return ;
    }
    temp.push_back(root->data);
    helper(root->left,key,k,temp,ans,nt) ;
    helper(root->right,key,k,temp,ans,nt) ;
    if(root->data == key){
        if(temp.size()<k){
            nt =  true;
        }
        else{
            ans = temp[temp.size()-k-1] ;
        }
    }
    temp.pop_back();


}
int method_3(node* root,int key,int k){
    if(!root) return-1;
    vector<int> temp;
    int ans = -1;
    bool nt = false;
    helper(root,key,k,temp,ans,nt);
    if(nt) return -1;

    return ans ;
    /*
    Time :O(N)
    Space : O(H)
    */

}
int main(){
    //creating tree;
    node* root = new node(5);

    root->left = new node(10);
    root->left->left = new node(25);
    root->left->right = new node(35);

    root->right = new node(12);
    root->right->left = new node(40);
    root->right->right = new node(20);

    cout<<method_3(root,20,2)<<endl;

   

    return 0;
}