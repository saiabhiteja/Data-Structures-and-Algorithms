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

void parentpointers(node* root,unordered_map<node*,node*>&mp){
        queue<node*>q;
        q.push(root);
        mp[root] =NULL ;
        while(q.size()!=0){
            node* curr = q.front();
            q.pop();
            if(curr->left){
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    node* findNode(node* root,int target){
        queue<node*> q;
        q.push(root);
        while(q.size()!=0){
            node* curr = q.front();
            q.pop();
            if(curr->data == target){
                return curr;
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
        }
        return NULL ;
    }
    int findDist(node* root, int a, int b) {
        if(!(root)){
            return 0;
        }
        int distance = 0;
        unordered_map<node*,node*>mp;
        parentpointers(root,mp);
        node* element1 = findNode(root,a);
        node* element2 = findNode(root,b);
        if(!(element1) || !(element2)){
            return 0;
        }
        unordered_map<node*,bool> visited ;
        queue<node*>q;
        q.push(element1);
        visited[element1] = 1;
        while(q.size()!=0){
            int size = q.size();
            for(int i = 0;i<size;i++){
                node* curr = q.front();
                q.pop();
                visited[curr] = 1;
                if(curr == element2){
                    return distance;
                }
                if(curr->left && !(visited[curr->left])){
                    q.push(curr->left);
                }
                if(curr->right && !(visited[curr->right])){
                    q.push(curr->right);
                }
                if(mp[curr] && !(visited[mp[curr]])){
                    q.push(mp[curr]);
                }
            }
            distance++;
        }
        return distance;
        
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

    cout<<findDist(root,25,20);
   

   

    return 0;
}