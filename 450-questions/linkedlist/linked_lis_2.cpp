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

//insert at head
void insert_at_head(node* &head,int data){
    node* temp = new node(data) ;
    temp->next = head ;
    head = temp ;
}
//delete function
void delete_node(node* &head,int val){
    node* curr = head ;

    while(curr->next->data != val){
        curr = curr->next;
    }
    node* todelete = curr->next ;
    curr->next = curr->next->next ;

    delete todelete ;

}

//delete at head
void deleteathead(node* &head){
    node* curr = head ;
    node* temp = head->next ;
    head = temp ;
    delete curr ;
}

void display(node* head){
    node* curr = head;
    while(curr){
        cout<<curr->data<<"->" ;
        curr = curr->next ;
    }
    cout<<"NULL";
}
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
node* get_node(int val,node* head){
    if(!head) return head;
    node* temp = head;
    while(temp && temp->data != val){
        temp = temp->next ;
    }
    return temp ;
}
/*
Revesing a group k nodes in a given linked list
*/
 node *reverse (struct node *head, int k)
    { 
        if(!head){
            return head ;
        }
        node* curr = head ;
        node* prev = NULL ;
        node* nxt = NULL ;
        int k2 = k;
        while(curr && k){
            nxt = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = nxt ;
            k--;
        }
        head->next = reverse(nxt,k2);
        return prev ;
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

    node* head2 = NULL ;
    insert_at_tail(head2,9);
    insert_at_tail(head2,4);
    insert_at_tail(head2,3);
    //display
    display(head);

    //reverse
    cout<<endl;
    head = reverse(head,2);
    display(head);


    return 0;
}


