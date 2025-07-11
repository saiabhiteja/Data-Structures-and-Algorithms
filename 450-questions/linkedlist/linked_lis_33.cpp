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

/**/


node *compute(node *head){
    if(!head) return head ;

    if(head==NULL && head->next==NULL) return head ;
    

    node *temp=head;
    node *pre=NULL;

    while(temp && temp->next){

    if(temp->data<temp->next->data){
        pre=temp->next;
        temp->data=pre->data;
        temp->next=pre->next;
        temp=head;
    }
    else{
        temp=temp->next;
    }

    }
    return head;
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
    head = compute(head);
    display(head);


    return 0;
}


