#include <iostream>
#include "bits/stdc++.h"
using namespace std;

struct node{
    int data;
    struct node* next;
     node(int x)
     {
         data = x;
         next = nullptr;
     }
};

//insert at tail
void insert_at_tail(node* &head,int data){
    node *temp = new node(data);
    node *curr = head ;
    //base condition
    if(curr == NULL){
        head = temp ;
    }
    else{ 
    while(curr->next ){
        curr = curr->next;
    }
    curr->next = temp ;}
}

void display(node* head){
    node* curr = head;
    while(curr){
        cout<<curr->data<<"->" ;
        curr = curr->next ;
    }
    cout<<"NULL"<<endl;
}

int method1(node* head1,node* head2){
    //node* temp = head1 ;
    unordered_map<node*,bool> mp ;
    for(auto temp = head1;temp;temp=temp->next){
        mp[temp] = true ;
    }
    for(auto temp = head2;temp;temp = temp->next){
        if(mp.find(temp)!=mp.end()){
            return temp->data ;
        }
    }
    return -1;
    /*
    Time : O(N)+O(M)
    space : O(N)
    */
}
int intersectPoint(node* head1, node* head2){
    node* h1 = head1;
    node* h2 = head2 ;
    while(h1 != h2){
        if(h1->next){
            h1 = h1->next ;
        }
        else{
            h1 = head2;
        }
        
        if(h2->next){
            h2 = h2->next;
        }
        else{
            h2 = head1 ;
        }
        
    }
    return h1->data;
    /*
    Time : O(N+M)
    Space : O(1)
    */
    
}

int main(){
    node* head = NULL ;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);

   


    return 0;
}


