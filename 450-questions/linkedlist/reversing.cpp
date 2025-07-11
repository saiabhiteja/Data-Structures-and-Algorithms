#include <iostream>
#include "bits/stdc++.h"
using namespace std;

struct node{
    int data;
    struct node* next;
     node(int d)
     {
         data = d;
         next = NULL;
     }
};

void reverse(node* &head){
    node* curr = head;
    node* prev = NULL;
    node* next;
    if(curr==NULL){
        return;
    }
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev ;

}

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

//display all elements
void display(node* &head){
    node* curr = head;
    while(curr){
        cout<<curr->data<<"->" ;
        curr = curr->next ;
    }
}

int main(){
    node* head = NULL ;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    display(head);
    reverse(head);
    cout<<"Reversed linked list:";
    display(head);
    return 0;
}
