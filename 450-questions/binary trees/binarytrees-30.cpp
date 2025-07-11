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
    printing all paths whose sum k 
    Note: not mandatory from root to leaf
*/
void helper(node* root,vector<node*>& roots){
    if(!root) return;
    roots.push_back(root) ;
    helper(root->left,roots);
    helper(root->right,roots) ;
}

void path_helper(node* root,int k,vector<vector<int>>& ans,vector<int>temp){

    if(!root){
        if(k == 0){
            ans.push_back(temp);
        }
        return ;
    }

    if(k == 0){
        ans.push_back(temp) ;
    }

    temp.push_back(root->data);
    path_helper(root->left,k-root->data,ans,temp) ;
    path_helper(root->right,k-root->data,ans,temp) ;
    
    temp.pop_back();


}
vector<vector<int>> k_sum_paths_1(node* root,int k){
    //brute force 
    /*
        taking each node and traversing in all possible ways and check sum 
        if equal to requried then push
    */
   vector<vector<int>> ans ;
   vector<node*> roots;
   helper(root,roots) ;
   for(auto it: roots){
       vector<int> temp ;
       path_helper(it,k,ans,temp);
   }

    set<vector<int>> s ;
    for(auto it: ans){
        s.insert(it);
    }

    ans.clear();
    for(auto it: s){
        ans.push_back(it);
    }

   return ans ;
   /*
   Time : O(2^N)
   Space : O(N)
   */

}


//optimisation
void ischeck(vector<vector<int>>& ans,int k ,vector<int> path){
    int curr_sum = 0;
    for(int j = path.size()-1;j>=0 ;j--){
        curr_sum+=path[j] ;
        if(curr_sum == k){
            vector<int> temp ;
            for(int i = j;i<path.size();i++){
                temp.push_back(path[i]);
            }
            ans.push_back(temp);
        }
    }
    /*
    Time : O(N*N) where n = Height of tree
    Space : O(H)
    */
}
void helper_(node* root,vector<vector<int>>& ans,vector<int>path,int k){

    if(!root) return ;
    path.push_back(root->data) ;
    helper_(root->left,ans,path,k) ;
    helper_(root->right,ans,path,k) ;

    ischeck(ans,k,path) ;
    path.pop_back();

    /*
    Time : O(N*H*H)
    Space : O(H)
    */


}
vector<vector<int>> get_sum_k_paths_2(node* root,int k){
    vector<vector<int>> ans;
    vector<int> path;
    helper_(root,ans,path,k);
    return ans ;
     /*
    Time : O(N*H*H)
    Space : O(H)
    */
}
int main(){
    node* root = new node(1);

    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(1);

    root->right = new node(-1);
    root->right->left = new node(4);
    root->right->right = new node(5);

    root->left->right->left = new node(1) ;
    root->right->left->left = new node(1) ;
    root->right->left->right = new node(2) ;
    root->right->right->right = new node(6);

    vector<vector<int>> ans = get_sum_k_paths_2(root,5) ;
   


    for(auto it: ans){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<"\n";
    }

   

    return 0;
}