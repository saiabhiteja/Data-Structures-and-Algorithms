#include <bits/stdc++.h>
using namespace std;

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

//function creating loop at a position
void loopHere(node* &head, int position)
{
    if(position==0) return;
    
    node* walk = head;
    node* temp = head;
    while(temp->next == NULL){
        temp = temp->next ;
    }
    for(int i=1; i<position; i++)
    {walk = walk->next;}

    temp->next = walk;
}

//Function to check if the linked list has a loop.
bool detectLoop(node* head)
{
    struct node* slow = head;
    struct node* fast = head;
        
    while(fast!=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return 1;
        }
    }

    return 0;
}

//display all elements
void display(node* &head){
    node* curr = head;
    while(curr){
        cout<<curr->data<<"->" ;
        curr = curr->next ;
    }
}


int main(){
    node* head = NULL ;

    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    //loophere
    //loophere(head,3)
    bool b = detectLoop(head);
    if(b){
        cout<<"Loop detected";
    }
    else{
        cout<<"No Loop" ;
    }
 
    
    return 0;
}

