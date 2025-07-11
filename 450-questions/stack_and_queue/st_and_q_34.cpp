#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    check wether all levels of a tree are anagrams or not
    https://www.geeksforgeeks.org/check-if-all-levels-of-two-trees-are-anagrams-or-not/
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
}

bool are_angrams(node* root1,node* root2){
    if(!root1 ^ !root2 ){
        return false ;
    }
    if(!root1 && !root2){
        return true;
    }
    queue<node*>q1,q2 ;
    q1.push(root1) ;
    q2.push(root2) ;
    while(q1.size()!=0 && q2.size()!=0){
        int s1 = q1.size() ;
        int s2 = q2.size() ;
        if(s1 != s2) return false ;
        vec t_1,t_2 ;
        for(int i = 0;i<s1;i++){
            node* t1 = q1.front() ;
            node* t2 = q2.front() ;
            q1.pop();
            q2.pop();
            t_1.push_back(t1->data) ;
            t_2.push_back(t2->data) ;
            if(t1->left){
                q1.push(t1->left) ;
            }

            if(t1->right){
                q1.push(t1->right) ;
            }

            if(t2->left){
                q2.push(t2->left) ;
            }

            if(t2->right){
                q2.push(t2->right) ;
            }
        }
        sort(t_1.begin(),t_1.end()) ;
        sort(t_2.begin(),t_2.end()) ;
        if(t_1 != t_2){
            return false;
        }
    }
    if(q1.size()|| q2.size()) return false;
    return true;
    /*
    Time : O(NlogN)
    Space : O(N)
    */
}
int main(){
    //creating tree;
    node* root1 = new node(5);

    root1->left = new node(10);
    root1->left->left = new node(25);
    root1->left->right = new node(35);

    root1->right = new node(12);
    root1->right->left = new node(40);
    root1->right->right = new node(20);

    node* root2 = new node(5);

    root2->left = new node(12);
    root2->left->left = new node(20);
    root2->left->right = new node(35);

    root2->right = new node(10);
    root2->right->left = new node(40);
    root2->right->right = new node(25);
   

    if(are_angrams(root1,root2)){
        cout<<"trees are anagrams"<<endl;
    }
    else{
        cout<<"trees are not anagrams"<<endl;
    }

   

    return 0;
}