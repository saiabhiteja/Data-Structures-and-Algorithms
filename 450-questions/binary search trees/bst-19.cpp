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
void postorder(node* root){
    if(!root) return ;
    postorder(root->left) ;
    postorder(root->right) ;
    cout<<root->data<<" ";
}
/*
construct tree from  given preorder 
*/
node* helper(int ino[],int pre[],int instart,int inend,int prestart,int preend,map<int,int>mp){
    if(instart>inend || prestart>preend){
        return NULL;
    }
    node* root = new node(pre[prestart]);
    int inroot = mp[root->data];
    int numsleft = inroot - instart ;
    root->left = helper(ino,pre,instart,inroot-1,prestart+1,prestart+numsleft,mp);
    root->right = helper(ino,pre,inroot+1,inend,prestart+numsleft+1,preend,mp);
    return root;
}
node* post_order(int pre[], int size)
{
    if(size == 0){
        return NULL ;
    }
    //creating inorder of given preorder
    int ino[1000] ;
    for(int i = 0;i<size;i++){
        ino[i] = pre[i];
    }
    sort(ino,ino+size);
    map<int,int> mp;
    for(int i = 0;i<size;i++){
        mp[ino[i]] = i;
    }
    return helper(ino,pre,0,size-1,0,size-1,mp);
    /*
    Time : O(N)
    Space : O(N)
    */
}

int main(){
    int arr[5]  = {40,30,35,80,100} ;
    node* ans = post_order(arr,5) ;
    postorder(ans);

   

    return 0;
}