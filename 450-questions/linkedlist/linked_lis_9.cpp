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
    cout<<"NULL";
}

/* add one to the linked list given*/
node* reverse(node* head){
        
        node* curr = head ;
        node* prev = NULL ;
        node* nxt = NULL ;
        while(curr){
            nxt = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = nxt ;
        }
        return prev ;
    }
    node* addOne(node *head) 
    {
        if(!head) return head ;
        head = reverse(head) ;
        int carry = 1; 
        node* temp = head;
        node* prev = NULL;
        while(carry!=0){
            int s  = 0; 
            if(temp){
               s = temp->data+carry ;
               temp->data = s%10 ;
               carry = s/10 ;
               prev = temp ;
               temp = temp->next ;
            }
            else{
                node* t = new node(1) ;
                prev->next = t ;
                carry = 0;
                
            }
        }
        head = reverse(head) ;
        return head ;
        /*
        Time : O(N) + O(N) + O(N)
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
    //display
    display(head);
    head = addOne(head);
    cout<<endl;
    display(head);




    return 0;
}


