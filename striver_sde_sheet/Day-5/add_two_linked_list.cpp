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
adding two linked lists;
*/
node* reverse(node* head){
        
        node* curr = head ;
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
    
    //Function to add two numbers represented by linked list.
    struct node* addTwoLists(struct node* first, struct node* second){
        if(!first){
            return second;
        }
        if(!second){
            return first ;
        }
        first = reverse(first);
        second = reverse(second);
        node* ans = new node(0) ;
        node* temp = ans ;
        node* h1 = first ;
        node* h2 = second ;
        int carry = 0 ;
        while(h1 || h2 || carry){
            int s = 0;
            if(h1){
                s+=h1->data ;
                h1 = h1->next ;
            }
            if(h2){
                s+=h2->data;
                h2 = h2->next ;
            }
            s+=carry ;
            temp->next = new node(s%10) ;
            carry = s/10 ;
            temp = temp->next ;
        }
        ans = reverse(ans->next);
        return ans ;
        /*
        Time : 2*(O(N)+O(M)) + O(N+M)
        Space : O(max(N,M)+1)
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
    cout<<endl;
    display(head2);
    head = addTwoLists(head,head2);
    cout<<endl;
    display(head);


    return 0;
}