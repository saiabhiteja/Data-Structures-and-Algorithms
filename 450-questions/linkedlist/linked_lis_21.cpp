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
        cout<<curr->data<<" <- ";
        curr = curr->prev ;
    }
    cout<<"Null"<<endl;
}
/*
 Find a pair whose sum is equals to target
*/
vector<vector<int>> find_req_sum(node* head, int target){
    vector<vector<int>> ans ;
    node* fir = head ;
    node* las = head ;
    while(las->next){
        las = las->next ;
    }
    while(fir!=las){
        int sum = fir->data + las->data ;
        if(sum == target){
            ans.push_back({fir->data,las->data});
            fir = fir->next ;
            las = las->prev ;
        }
        else if(sum>target){
            las = las->prev ;
        }
        else{
            fir = fir->next ;
        }
    }
    return ans ;
    /*
    Time : O(N) + O(N)
    Space : O(1)
    */
}

int main(){
    node* head = NULL ;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    insert_at_tail(head,8);
    insert_at_tail(head,9);

    reverse_display(head);
    vector<vector<int>> ans = find_req_sum(head,7);

    for(auto it: ans){
        cout<<it[0]<<" "<<it[1]<<endl;
    }


    return 0;
}


