#include <iostream>
#include "bits/stdc++.h"
using namespace std;

struct node{
    int data;
    struct node* next;
    struct node* prev ;
     node(int x)
     {
         data = x;
         next = nullptr;
         prev = nullptr ;
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
        curr->next->prev = curr ;
        curr = curr->next;
    }
    curr->next = temp ;
    temp->prev = curr ;
    }
}

void display(node* head){
    node* curr = head;
    while(curr){
        cout<<curr->data<<"->" ;
        curr = curr->next ;
    }
    cout<<"NULL"<<endl;
}

void reverse_display(node* head){
    node* curr = head ;
    while(curr->next){
        curr = curr->next ;
    }
    while(curr){
        cout<<curr->data<<" <- ";
        curr = curr->prev ;
    }
    cout<<"Null"<<endl;
}
/*
 sort a k sorted linked list
*/
struct compare{
    bool operator()(node* p1,node* p2){
        return p1->data>p2->data ;
    }

};
node* sort_linked_lis(node* head,int k){
    if(!head) return head;
    priority_queue<node*,vector<node*>,compare> pq;

    for(int i = 0;head!=NULL && i<=k;i++){
        pq.push(head);
        head = head->next ;
    }
    node* new_head = NULL ;
    node* last = NULL ;
    while(pq.size()!=0){

        if(new_head == NULL){
            new_head = pq.top();
            new_head->prev = NULL ;
            last = new_head ;
        }
        else{
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
        pq.pop();
        if(head){
            pq.push(head);
            head = head->next ;
        }
    }
    last->next = NULL ;
    return new_head ;
    /*
    Time : O(N*logk)
    Space: O(k)
    */

}


int main(){
    node* head = NULL ;
    insert_at_tail(head,3);
    insert_at_tail(head,6);
    insert_at_tail(head,2);
    insert_at_tail(head,12);
    insert_at_tail(head,56);
    insert_at_tail(head,8);
  

    //reverse_display(head);
    head = sort_linked_lis(head,2) ;
    display(head);
    


    return 0;
}


