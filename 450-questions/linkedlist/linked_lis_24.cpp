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
 Rotate by N Nodes
*/
node* method_1(node* head,int k){
    if(!head) head ;
    node* req = head ;
    node* last = head ;

    for(int i = 1;i<k;i++){
        req = req->next ;
        last = last->next ;
    }
    while(last->next){
        last = last->next ;
    }

    last->next = head ;
    head->prev = last ;

    req->next->prev = NULL ;
    node* ans = req->next ;
    req->next= NULL ;

    return ans;
    /*
    Time : O(N)
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
    insert_at_tail(head,6);
  

    //reverse_display(head);
    head = method_1(head,2) ;
    display(head);
    


    return 0;
}


