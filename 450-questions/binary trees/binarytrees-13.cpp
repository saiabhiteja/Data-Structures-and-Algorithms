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
vector<vector<int>> zig_zag(node* root){
    int flag = 0;
    vector<vector<int>>ans;
    queue<node*> q;
    q.push(root);
    while(q.size()!=0){
        int count = q.size();
        vector<int> temp;
        for(int i = 0;i<count;i++){
            node* t = q.front();
            q.pop();
            temp.push_back(t->data);
            if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
            }
        }
        if(flag == 0){
            ans.push_back(temp);
            flag = 1;
        }
        else {
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            flag = 0;
        }
        
    }
    return ans;

}

vector<vector<int>> zigzag_2(node* root){
    bool flag = true;
    vector<vector<int>>ans;
    queue<node*> q;
    q.push(root);
    while(q.size()!=0){
        int count = q.size();
        vector<int> temp(count);
        for(int i = 0;i<count;i++){
            node* t = q.front();
            q.pop();
            //instead of using reverse every time we can use index
            //here flag acts a direction teller wether r->l or l->r;
            int index = (flag)? i:count-i-1 ;
            temp[index] = t->data;
            if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
            }
        }
        flag = !flag ;
        ans.push_back(temp);
        
        
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

    //levelorder
    level_order(root);
    cout<<endl;

    //ans
    vector<vector<int>> ans = zig_zag(root);
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
    }
    cout<<endl ;

    vector<vector<int>> an = zigzag_2(root);
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<an[i][j]<<" ";
        }
    }
    cout<<endl ;

   

    return 0;
}