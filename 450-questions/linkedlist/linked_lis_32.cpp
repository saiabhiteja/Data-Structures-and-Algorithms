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
Multiplying two numbers which are given in linked lists
*/

long long  multiplyTwoLists (node* l1, node* l2)
{
  //Your code here
  long long  num1=0,num2=0;
  long long N=1000000007;
  while(l1){
      num1 = ((num1%N)*10)%N + l1->data ;
      l1 = l1->next ;
  }
  while(l2){
      num2 = ((num2%N)*10)%N + l2->data ;
      l2 = l2->next ;
  }
  
  return ((num1%N)*(num2%N))%N ;
  /*
  Time : O(N) + O(M)
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

    node* head2 = NULL ;
    insert_at_tail(head2,9);
    insert_at_tail(head2,4);
    insert_at_tail(head2,3);
    //display
    display(head);

    cout<<multiplyTwoLists(head,head2)<<endl;


    return 0;
}


