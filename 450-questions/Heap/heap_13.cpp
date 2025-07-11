#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL 
#define in INT_MAX
#define im INT_MIN 
/*
    check if binary tree is max heap 

*/
struct node{
    int data ;
    node *right,*left ;
    node(int x){
        data = x ;
        right = nu ;
        left = nu ;
    }
} ;
bool maxi(node* root,int par){
    //function for checking wether parent is maximum of left and right
    if(!root) return true ;
    if(root->data>par) return false ;
    return (maxi(root->left,root->data) && maxi(root->right,root->data)) ;

    /*
    Time : O(N)
    space : O(N)
    */

}
bool complete(node* root){
    //function for checking complete tree or not
    queue<node*> q ;
    q.push(root) ;
    bool isfound = false ;
    while(q.size()!=0){
        node* temp = q.front() ;
        q.pop() ;

        if(temp->left){
            if(isfound) return false ;
            q.push(temp->left) ;
        }
        else{
            isfound = true;
        }

        if(temp->right){
            if(isfound) return false ;
            q.push(temp->right);
        }
        else{
            isfound = true;
        }

    }
    return true ;

    /*
    Time : O(N)
    space : O(N)
    */

}
bool ismaxheap(node* root){
    if(!root) return false;

    return (maxi(root,INT_MAX) && complete(root)) ;

}

//2nd method
int dfs(node *root, int par) {
        
        if(!root) 
        return 0;
        
        if(root->data > par)
        return -1;
        
        int left = dfs(root->left, root->data);
        int right = dfs(root->right, root->data);
        //for complete tree left-right = 0 or left-right = 1 if not then it is not complete tree
    if(left == -1 || right == -1 || left - right < 0 || left - right > 1)
    return -1;
        
        return left + 1;
    }
  
bool isHeap(struct node* root) {
    return dfs(root, INT_MAX) != -1;
    /*
    Time : O(N)
    space : O(N) 
    */
}
int main() {
    node* root = nu ;
   //creating tree;
    root = new node(50);

    root->left = new node(40);
    root->left->left = new node(30);
    root->left->right = new node(20);

    root->right = new node(10);
    root->right->left = new node(4);
    root->right->right = new node(2);
    if(ismaxheap(root)){
        cout<<"Max Heap"<<endl ;
    }
    else{
        cout<<"Not a Max Heap"<<endl;
    }
    return 0;
}