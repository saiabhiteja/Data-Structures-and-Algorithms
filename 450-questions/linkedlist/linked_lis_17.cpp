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
        if(curr ==head){
            break;
        }
    }
    cout<<endl;
}
node* get_node(int val,node* head){
    if(!head) return head;
    node* temp = head;
    while(temp && temp->data != val){
        temp = temp->next ;
    }
    return temp ;
}
/*
    splitting circular linked list into two halves
*/

void splitList(node *head, node **head1_ref, node **head2_ref)
{
    node *slow = head, *fast = head;
    //finding middle element
    while(fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    *head1_ref = head;
    *head2_ref = slow->next;
    
    node *temp = slow->next;
    
    slow->next = head;
    
    node *curr = *head2_ref;
    
    while(curr->next != head)
    {
        curr=curr->next;
    }
    
    curr->next = *head2_ref;
    
}


int main(){

    node* head = NULL ;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    node* t = get_node(5,head);
    t->next = head ;
    display(head);

    node* head1 = NULL ;
    node* head2 = NULL ;
    splitList(head,&head1,&head2) ;
    display(head1);
    display(head2);


    return 0;
}


