#include "bits/stdc++.h"
using namespace std ;
struct node{
    int data;
    struct node* next;
     node(int d)
     {
         data = d;
         next = NULL;
     }
};

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

//display all elements
void display(node* &head){
    node* curr = head;
    while(curr){
        cout<<curr->data<<"->" ;
        curr = curr->next ;
    }
    cout<<"NULL"<<endl;
}
/*
-> reversing a linked list
brute:
    using extra space 
    1) we can use stack and reverse since stack follows lifo
    2) we can use array and reverse it using inbuilt reverse function
    complexity:
    TIME :O(N)
    SPACE:O(N)
optimised:
    inplace
    reversing orginal linked list
    1.iteration
    2.recursion
    complexity:
    TIME :O(N)
    SPACE:O(1)
*/
node* reverse_iter(node* head){
    //if root is null return null
    if(!head) return head ;
    //iteration
    node* curr = head ;//current pointer
    node* nxt = NULL; //next pointer
    node* prev = NULL ;//previous pointer

    while(curr){ //if curent becomes null then we came to end of our linked list
        nxt = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = nxt ;
    }

    return prev; //when current becomes null previous points one before element of that ie, 
    //last element of orginal linked list which is now head of our reversed linked list

    /*
    complexity:
    Time : O(N);
    space : O(1); only pointers are used ;
    */

}

node* reverse_recur(node* head){

    if(!head) return head ; //if null return null
    if(!head->next) return head ;//if only one node then return head 
    node* last = reverse_recur(head->next) ;
    /*
     if we have a->b->c->null  our output should  null<-a<-b<-c 
     1. we call function when head is pointing on a (head->a)
        reverse_recur(head->a)
        here last = c,head = a,head->next->next = b->next = a
        a->next = head->next = NULL
        so linked list = null<-a<-b<-c
        our head is now c and last is pointing on it so we return last 
            |
        reverse_recur(head->b) 
        here last = c , head = b,head->next->next = c->next;c->next = b
        head->next = b->next = NULL so linked list is a->b<-c again we return c from here 
                                                         |
                                                         NULL
            |
        reverse_recur(head->c) since c->next is null so it returns c
    */
    head->next->next = head ;
    head->next = NULL ;
    return last ;
    /*
    Time : O(n)
    SPACE : O(1) {EXCLUDING RECURSIVE STACK}
    */

}
int main(){
     node* head = NULL ;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    display(head);
    head = reverse_iter(head) ;
    display(head);
    head = reverse_recur(head) ;
    display(head) ;
    
    return 0 ;
}