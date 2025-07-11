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

/*
circular linked list or not
*/
bool isCircular(node *head)
{
   // Your code here
   node* temp =head;
   while(temp)
   {
       if(temp->next == head)
       {
           return true;
       }
       temp = temp->next;
   }
   return false;
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
    //display
    display(head);

    if(isCircular(head)){
        cout<<"linked list is circular"<<endl;
    }
    else{
        cout<<"Not circular"<<endl;
    }


    return 0;
}


