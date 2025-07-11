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
Finding Middle element
*/
int length(node* head){
    if(!head) return 0;
    node* temp =head ;
    int len = 0;
    while(temp){
        len++;
        temp = temp->next ;
    }
    return len;
    /*
    Time : O(N)
    Space : O(1)
    */
}

void middle(node* head){
    if(!head) return;
    int len = length(head);
    len = (len+1)/2 ;
    node* temp = head ;
    for(int i = 1;i<len;i++){
        temp = temp->next ;
    }
    cout<<"middle element : "<<temp->data<<endl;
    /*
    Time : O(N) + O(N/2)
    Space : O(1)
    */
}

void middle_2(node* head){
    //using fast and slow pointers concept
    if(!head) return;
    node* fast = head;
    node* slow = head ;
    while(fast && fast->next){
        fast = fast->next->next ;
        slow = slow->next ;
    }
    cout<<"Middle element :"<<slow->data<<endl;
    /*
    Time :O(N/2)
    Space :O(1)
    */
}


int main(){
    node* head = NULL ;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);

    middle(head);
    middle_2(head);


    return 0;
}


