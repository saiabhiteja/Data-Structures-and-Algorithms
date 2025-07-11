#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
converting bst to min heap
https://www.geeksforgeeks.org/convert-bst-min-heap/
*/
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
    cout<<endl;
}

void inorder(node* root,vec& ino){
    if(!root) return ;
    inorder(root->left,ino) ;
    ino.push_back(root->data);
    inorder(root->right,ino) ;
    /*
    Time : O(N)
    space : O(N)
    */
}
void preorder(node* root,int& ind,vec ino){
    if(!root) return ;
    root->data = ino[ind++] ;
    preorder(root->left,ind,ino);
    preorder(root->right,ind,ino) ;
    /*
    Time : O(N)
    space : O(N)
    */
}
void convert(node* root){
    if(!root) return ;
    vec ino ;
    inorder(root,ino) ;
    int ind = 0;
    preorder(root,ind,ino) ;

}
int main(){
    //creating tree;
    node* root = new node(15);

    root->left = new node(13);
    root->left->left = new node(12);
    root->left->right = new node(14);

    root->right = new node(20);
    root->right->left = new node(16);
    root->right->right = new node(24);
    

    //display
    level_order(root);

    convert(root) ;

    level_order(root) ;

   

    return 0;
}