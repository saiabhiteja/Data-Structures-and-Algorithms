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
nth node from last of the linked list
*/
int getNthFromLast(node *head, int n)
{
    node* temp = head ;
    int len = 0;
    while(temp){
        len++;
        temp = temp->next;
    }
    int pos = len-n ;
    if(pos<0){
        return -1;
    }
    temp = head;
    for(int i = 0;(i<pos) &&(temp);i++){
        temp = temp->next ;
    }
    return temp->data;
    /*
    Time :O(N)
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

    cout<<getNthFromLast(head,2);


    return 0;
}


