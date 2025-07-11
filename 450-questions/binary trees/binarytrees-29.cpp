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
Finding maximum sum of non adjancet nodes
*/
unordered_map<node*,int> dp ;
int getMaxSum(node *root)  {
        if(!root){
            return 0;
        }
        if(dp[root]!=0){
            return dp[root];
        }

        int gc = root->data;
        if(root->left){
            //grandchildren sum
            gc+=getMaxSum(root->left->left);
            gc+=getMaxSum(root->left->right);
        }
        if(root->right){
            gc+=getMaxSum(root->right->right);
            gc+=getMaxSum(root->right->left);
        }
        //children sum
        int c = getMaxSum(root->left);
        c+=getMaxSum(root->right);
        dp[root] = max(c,gc);
        return dp[root];
        /*
        Time : O(N)
        Space : O(N)
        */
}

pair<int,int> method2(node* root){
    /*
    using pairs -> pair(include ,exclude)

    */
   if(!root) return {0,0} ;
    pair<int,int> p1 = method2(root->left) ;
    pair<int,int> p2 = method2(root->right) ;
    pair<int,int> curr ;
    //include current element
    curr.first = p1.second + p2.second + root->data ;
    //exclude element
    curr.second = max(p1.first,p1.second)+max(p2.first,p2.second);
    return curr;

    /*
    Time : O(N)
    Space : O(N)
    */

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

    pair<int,int> p1 = method2(root) ;
    int ans = max(p1.first,p1.second) ;
    cout<<ans<<endl;

   

    return 0;
}