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

vector<int>  inorder_traversal_2(node* root){
    vector<int> ans ;
    //using stack
    stack<node*> st;
    node* t = root;
    while(t || st.size()!=0){
        if(t!=NULL){
            st.push(t);
            t = t->left;
        }
        else{
            t = st.top();
            ans.push_back(t->data);
            st.pop();
            t = t->right;
        }

    }
    return ans;

}

vector<int> print_itretative_preoder(node * root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    stack<node*>st;
    
    st.push(root);
    while(st.size()!=0){
        node* t = st.top();
        ans.push_back(t->data);
        st.pop();
        if(t->right){
            st.push(t->right);
        }
        if(t->left){
            st.push(t->left);
        }
       
    }
    return ans;
}

//method-1
node* helper(vector<int> inorder,vector<int> preorder,int instart,int inend,int prestart,int preend,map<int,int>mp){
    if(instart>inend || prestart>preend){
        return NULL ;
    }
    node* root = new node(preorder[prestart]);
    int inroot = mp[root->data];
    int numsleft = inroot-instart;
    root->left = helper(inorder,preorder,instart,inroot-1,prestart+1,prestart+numsleft,mp) ;
    root->right = helper(inorder,preorder,inroot+1,inend,prestart+numsleft+1,preend,mp);
    return root;
}

node* constructtree(vector<int> inorder,vector<int> preorder){
    if(inorder.size() == 0){
        return NULL ;
    }
    //map for indexes of inorder
    int n = inorder.size();
    map<int,int> mp ;
    for(int i = 0;i<n;i++){
        mp[inorder[i]] = i;
    }

    return helper(inorder,preorder,0,n-1,0,n-1,mp);
}

//2nd method

//we can use map and remove this function as in method 1
int search(int inoder[],int curr,int start,int end)
{
    for(int i = start;i<=end;i++)
    {
        if(curr == inoder[i])
        {
            return i;
        }
    }
    return -1;
    
}
node * buildtree(int preoder[],int inoder[],int start,int end)
{
    if(start>end)
    {
        return NULL  ;
    }
    static int idx = 0;
    int curr = preoder[idx];
    idx++;
    node* root= new node(curr);
    if(start == end)
    {
        return root;
    }
    int pos = search(inoder,curr,start, end);
    root->left = buildtree(preoder,inoder,start,pos-1);
    root->right = buildtree(preoder,inoder,pos+1,end);
    return root;
    
    
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

    //inorder
    vector<int> inorder = inorder_traversal_2(root);

    //prorder
    vector<int> preorder = print_itretative_preoder(root);

    //constructing 
    node* root2 = constructtree(inorder,preorder) ;

    //printing level order 
    level_order(root);
    cout<<endl ;
    level_order(root2);

   

    return 0;
}