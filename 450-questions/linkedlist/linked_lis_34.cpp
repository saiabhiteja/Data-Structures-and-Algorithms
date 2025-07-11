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
Segregate even and odd nodes in a Link List
*/
node* divide(int N, node *head){
        // code here
         
       if(head==0 || head->next==0)
           return head;
           
       node* curr=head;
       node* even =new node(0);
       node* odd =new node(0);
       
       node* temp1 = even;
       node* temp2 = odd;

       while(curr)
       {
           if(curr->data%2==0)
           {
               temp1->next=curr;
               temp1= temp1->next;
               
           }
           else
           {
               temp2->next= curr;
               temp2=temp2->next;
           }
           curr=curr->next;
       }
          
         
      temp1->next = odd->next;
           
   //end the list        
      temp2->next = NULL; 
      
      return even->next;
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
    node* ans = divide(5,head);
    display(ans);


    return 0;
}


