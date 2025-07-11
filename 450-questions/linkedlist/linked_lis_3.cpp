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
detecing loop in a linked list
*/
bool is_loop(node* head){
    if(!head){
        return false;
    }
    unordered_map<int,node*> mp;
    while(head){
        if(mp[head->data]){
            if(mp[head->data] == head){
                return true;
            }
        }
        mp[head->data] = head ;
        head = head->next;
    }
    return false;
    /*
    Time : O(N)
    Space :O(N)
    */
}

bool iscycle_2(node* h1){
    if(!h1) return false;
    node* slow = h1;
    node* fast = h1 ;

    while(slow &&fast && fast->next){
        slow = slow->next ;
        fast = fast->next->next ;
        if(slow == fast){
            return true;
        }
    }
    return false;
    /*
    Time: O(N)
    Space :O(1)
    */
}

int main(){
    node* head = NULL ;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);

    node* t = get_node(5,head);
    t->next = get_node(2,head) ;

    if(iscycle_2(head)){
        cout<<"Cycled"<<endl;
    }
    else{
        cout<<"Not cycled"<<endl ;
    }


    return 0;
}


