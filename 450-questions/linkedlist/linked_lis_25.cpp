#include <iostream>
#include "bits/stdc++.h"
using namespace std;

struct node{
    int data;
    struct node* next;
    struct node* prev ;
     node(int x)
     {
         data = x;
         next = nullptr;
         prev = nullptr ;
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
        curr->next->prev = curr ;
        curr = curr->next;
    }
    curr->next = temp ;
    temp->prev = curr ;
    }
}

void display(node* head){
    node* curr = head;
    while(curr){
        cout<<curr->data<<"->" ;
        curr = curr->next ;
    }
    cout<<"NULL"<<endl;
}

void reverse_display(node* head){
    node* curr = head ;
    while(curr->next){
        curr = curr->next ;
    }
    while(curr){
        cout<<curr->data<<" -> ";
        curr = curr->prev ;
    }
    cout<<"Null"<<endl;
}
/*
    reversing a double linked list
*/

node* reverse(node* head){
    if(!head) return head ;
    node* nxt = head ;
    node* curr = head ;
    while(nxt){
        nxt = curr->next ;
        node* temp = curr->prev ;
        curr->prev = curr->next ;
        curr->next = temp ;
        if(nxt){
            curr = nxt;
        }

    }
    return curr;
    /*
    Time : O(N)
    Space : O(1)
    */
}
node* reverse_2(node* head,int k){
    //reversing nodes of size k everytime
    if(!head) return head;
    int j = k ;

    node* curr = head ;
    node* nxt = head;

    while (j && nxt){
        nxt = curr->next;
        node* temp = curr->prev ;
        curr->prev = curr->next ;
        curr->next = temp;
        
        j--;
        if(nxt && j){
            curr = nxt ;
        }
    }

    if(!nxt) return curr ;
    curr->prev = NULL ;
    nxt->prev = NULL ;

    node* remaing = reverse_2(nxt,k);

    if(!remaing) return curr ;

    remaing->prev = head ;
    head->next = remaing ;

    return curr ;
    /*
    Time : O(N)
    Space : O(N)
    */

}


int main(){
    node* head = NULL ;
    insert_at_tail(head,3);
    insert_at_tail(head,6);
    insert_at_tail(head,2);
    insert_at_tail(head,12);
    insert_at_tail(head,56);
    insert_at_tail(head,8);
    insert_at_tail(head,9);
    insert_at_tail(head,98);
  
    display(head);
    //reverse_display(head);
    head = reverse_2(head,3) ;
    display(head);
    //reverse_display(head);
    


    return 0;
}


