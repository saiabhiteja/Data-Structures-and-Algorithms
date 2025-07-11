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
check if linked list is palindrome or not
*/
node* middle(node* head){
    if(!head) return head ;
    node* slow_ptr = head ;
    node* fast_ptr = head ;
    while(fast_ptr && fast_ptr->next){
        fast_ptr = fast_ptr->next->next ;
        if(fast_ptr)
        slow_ptr = slow_ptr->next ;
    }
    return slow_ptr ;
}
node* reverse(node* head){
    node* curr = head;
    node* prev = NULL ;
    node* nxt = NULL ;
    while(curr){
        nxt = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = nxt ;
    }
    return prev ;
}
bool isPalindrome(node *head){
    node* mid = middle(head);
    node* m_next = mid->next ;
    mid->next = reverse(m_next) ;
    m_next = mid->next ;
    node* temp = head ;
    while(temp && m_next){
        if(temp->data!= m_next->data){
            return false;
        }
        temp = temp->next;
        m_next = m_next->next ;
    }

    return true;
    /*
    Time : O(N)
    Space : O(1)
    */
        
}

int main(){
    node* head = NULL ;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    //insert_at_tail(head,3);
    insert_at_tail(head,2);
    insert_at_tail(head,1);
    //display
    display(head);
    if(isPalindrome(head)){
        cout<<"Linked list is palindrome"<<endl;
    }
    else{
        cout<<"Not a Palindrome"<<endl;
    }


    return 0;
}


