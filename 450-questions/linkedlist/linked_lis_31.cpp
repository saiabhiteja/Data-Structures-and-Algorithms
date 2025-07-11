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
Merging k sorted linked lists
*/
node* merge(node* head1,node* head2){
    if(!head1) return head2;
    if(!head2) return head1 ;
    node* result = NULL ;
    //just making sure everytime we have head1 pointing less value
    if(head2->data<head1->data){
        swap(head2,head1) ;
    }
    result = head1 ;
    while(head1 && head2){
        node* prev = NULL ;
        while(head1 && head1->data<=head2->data){
            prev = head1;
            head1 = head1->next;
        }
        prev->next = head2 ;
        swap(head1,head2);
    }
    return result ;
    /*
    Time : O(l1+l2)
    Space : O(1)
    */
}
node * mergeKLists(node *arr[], int k)
    {
        node* ans = NULL ;
         for(int i = 0;i<k;i++){
             ans = merge(ans,arr[i]);
         }
         return ans;
         /*
         Time : O(N*k)
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
    insert_at_tail(head2,10);
    insert_at_tail(head2,13);

     node* head3 = NULL ;
    insert_at_tail(head3,9);
    insert_at_tail(head3,16);
    insert_at_tail(head3,17);
    //display
    node* arr[3] = {head,head3,head2} ;
    node* ans = mergeKLists(arr,3);
    display(ans);


    return 0;
}


