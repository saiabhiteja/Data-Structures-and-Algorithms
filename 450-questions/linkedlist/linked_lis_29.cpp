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
    sort linked list with only 0,1,2
*/
node* segregate(node *head) {
        int ones = 0;
        int zeroes = 0;
        int twos = 0;
        node* temp = head;
        while(temp!=NULL){
            if(temp->data == 0){
                zeroes++;
            }
            else if(temp->data == 1){
                ones++;
            }
            else{
                twos++;
            }
            temp = temp->next;
        }
        node* temp2 = head;
        int i = 0;
        while(temp2!=NULL){
            if(i<zeroes){
                temp2->data = 0;
            }
            else if(zeroes<=i && i<(zeroes+ones)){
                temp2->data = 1;
            }
            else{
                temp2->data = 2;
            }
            i++;
            temp2 = temp2->next;
        }
        return head;
        
        /*
        Time :O(N)
        Space : O(1)
        */
        
    }

int main(){
    node* head = NULL ;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,0);
    insert_at_tail(head,1);
    insert_at_tail(head,0);

    //display
    display(head);
    head = segregate(head);
    display(head);

    return 0;
}


