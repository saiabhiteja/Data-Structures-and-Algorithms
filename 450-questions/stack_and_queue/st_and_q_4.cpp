#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    desgining stack with tc o(1) finding middle element
    https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/
*/
//using doubly linked list
struct node{
    int data ;
    node* prev;
    node* next ;
    node(){
        prev = NULL ;
        next = NULL ;
    }

    node(int x){
        data = x ;
        prev = NULL ;
        next = NULL ;
    }
};

class Stack{
    private:
    node* head;
    node* mid ;
    int size ;
    public:
    Stack(){
        head = new node();
        mid = NULL ;
        size = 0;  
    }

    void push(int data){
        //since we are desging stack which uses LIFO Last In First Out
        //we add elements to the end
        node* temp = new node(data);
        if(size == 0){
            head = temp ;
            mid = temp ;
            size++;
        }
        else{
            head->next = temp ;
            temp->prev = head ;
            head = head->next;
            size++;
        }
        
        if(size%2 == 0){
            mid = mid->next ;
        }
      
        /*
        Time : O(1)
        */

    }

    void pop(){
        if(!head){
            return ;
        }
        if(size == 1){
            head = NULL ;
            mid = NULL ;
            size--;
        }
        else{
            head = head->prev ;
            head->next = NULL ;
            size--;
            if(size%2 == 1){
            mid = mid->prev ;
             }
        }
        /*
        Time : O(1)
        */
        
    }

    int get_mid(){
        if(!mid) return 0;
        return mid->data ;

    }

    void delete_mid(){
        if(size == 0){
            return ;
        }
        if(size == 1){
            mid = NULL;
            head = NULL ;
            size--;
        }
        else if(size == 2){
            mid = mid->prev ;
            head = head->prev ;
            head->next->prev = NULL ;
            head->next = NULL ;
            size--;
        }
        else{
            node* new_mid = NULL;
            if(size%2 == 1){
                new_mid = mid->next ;
            }
            else{
                new_mid = mid->prev ;
            }
            mid->prev->next = mid->next ;
            mid->next->prev = mid->prev ;

            size-- ;
            mid = new_mid ;
        }
        /*
        Time : O(1)
        */
    }


};

int main() {

    //creating stack
    Stack s1 ;

    s1.push(5) ;
    s1.push(23);
    s1.push(99);

    cout<<s1.get_mid()<<endl;

    s1.push(69);
    s1.push(68);

    cout<<s1.get_mid()<<endl;

    s1.pop();

    cout<<s1.get_mid()<<endl;
    s1.delete_mid() ;

    cout<<s1.get_mid()<<endl;



    return 0;
}