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

node* build(string s){
    if(s.size() == 0){
        return NULL ;
    }
    if(s.size() == 1){
        return new node(s[0]-'0') ;
    }

    node* root = new node(s[0]-'0') ;

    int open = 0;
    int close = 0;

    string left_part,right_part;
    int i ,cnt = 0;
    for( i = 1;i<s.size();i++){
        if(s[i] == '('){open++ ;}
        if(s[i] == ')'){close++ ;}
        if(open == close){break ;}
    }
    left_part = s.substr(2,i-2) ;
    if(i+2<s.size()){
        right_part = s.substr(i+2) ;
        right_part.pop_back();
    }
    else{
        right_part = "";
    }
    cout<<left_part<<endl;
    cout<<right_part<<endl;

    root->left = build(left_part);
    root->right = build(right_part);
    return root ;

    /*
    Time : O(N*len(s))
    Space : O(N)
    */
}
int main(){
    string s = "4(2(3)(1))(6(5))" ;
    node* root = build(s) ;
    level_order(root);
   

    return 0;
}