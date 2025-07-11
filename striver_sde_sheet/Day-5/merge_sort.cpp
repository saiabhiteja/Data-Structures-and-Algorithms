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
Merge sort on linked lists
*/
node* middle(node* head){
    //function for getting middle of the linked list
        if(!head) return head ;
        node* slow_ptr = head;
        node* fast_ptr = head;
        while(fast_ptr!=NULL && fast_ptr->next!= NULL){
            fast_ptr = fast_ptr->next->next ;
            if(fast_ptr)
            slow_ptr = slow_ptr->next ;
        }
        return slow_ptr ;
        /*
        Time : O(N)
        Space : O(1)
        */
    }
    node* merge(node* head1,node* head2){
        //function for merging two linked lists
        if(!head1){
            return head2;
        }
        if(!head2){
            return head1;
        }
        node* new_head = new node(10);
        node* temp = new_head ;
        while(head1 && head2){
            if(head1->data < head2->data){
                temp->next = new node(head1->data) ;
                temp = temp->next;
                head1 = head1->next ;
            }
            else{
                temp->next = new node(head2->data);
                temp = temp->next ;
                head2 = head2->next ;
            }
        }
        if(head1){
            temp->next = head1;
        }
        if(head2){
            temp->next = head2 ;
        }
        return new_head->next ;
        /*
        Time : O(Min(N,M))
        Space : O(N+M)
        */
    }
    node* mergeSort(node* head) {
        if(head == NULL){
            return head;
        }
        else if(head->next == NULL){
            return head;
        }
        else{
            node* mid = middle(head);
            node* nxt = mid->next ;
            mid->next = NULL ;
            node* left = mergeSort(head);
            node* right = mergeSort(nxt);
            return merge(left,right);
        }
        /*
        Time : O(N*logN)
        Space :O(N)
        */
    }
int main(){
    node* head = NULL ;
    insert_at_tail(head,11);
    insert_at_tail(head,2);
    insert_at_tail(head,33);
    insert_at_tail(head,41);
    insert_at_tail(head,5);

    //display
    display(head);

    head = mergeSort(head);

    display(head);


    return 0;
}