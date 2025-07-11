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

vector<int> top_veiw(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,int> mp;
    queue<pair<node*,int>> q;
    q.push({root,0});
    while(q.size()!=0){
        auto p = q.front();
        q.pop();
        node* temp = p.first;
        int vertical = p.second ;
        if(mp.find(vertical)==mp.end()){
            mp[vertical] = temp->data;
        }
        if(temp->left){
            q.push({temp->left,vertical-1});
        }
        if(temp->right){
            q.push({temp->right,vertical+1});
        }
    }
    for(auto t:mp){
        ans.push_back(t.second);
    }
    return ans;

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

    //top-veiw
    vector<int> ans = top_veiw(root);
    for(auto it:ans){
        cout<<it<<" ";
    }

   

    return 0;
}