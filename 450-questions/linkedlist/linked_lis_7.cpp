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
Removing duplicates from unsorted linked list
*/
node * removeDuplicates( node *head) {
        unordered_map<int,node*> mp;
        node* curr = head;
        node* prev = NULL ;
        while(curr){
            if(mp.find(curr->data) == mp.end()){
                mp[curr->data] = curr ;
                prev = curr ;
                curr = curr->next ;
            }
            else{
                prev->next = curr->next ;
                curr = curr->next ;
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
    insert_at_tail(head,3);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);

    //display
    display(head);
    head = removeDuplicates(head);
    cout<<endl;
    display(head);


    return 0;
}


