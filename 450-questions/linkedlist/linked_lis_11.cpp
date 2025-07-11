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
    cout<<"NULL"<<endl;
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

/* intersection of two sorted linked lists*/
node* findIntersection(node* head1, node* head2)
{
    node* temp1 = head1 ;
    node* temp2 = head2 ;
    node* curr = new node(0);
    node* head = curr ;
  
    while(temp1 && temp2)
    {
         if(temp1->data == temp2->data)
        {
            curr->next = new node(temp1->data);
            curr = curr->next ;
            temp1 = temp1->next ;
            temp2 = temp2->next ;
       }
       else if(temp1->data<temp2->data)
       {
           temp1= temp1->next;
       }
       else
       {
           temp2 = temp2->next;
       }
    }
    
    return head->next;
    /*
    Time : O(N+M)
    space : O(N)
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
    insert_at_tail(head2,2);
    insert_at_tail(head2,4);
    insert_at_tail(head2,5);
    //display
    display(head);
    display(head2);


    node* ne = findIntersection(head,head2) ;
    display(ne) ;


    return 0;
}


