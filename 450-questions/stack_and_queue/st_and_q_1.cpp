#include "bits/stdc++.h"
using namespace std;

//stack implementation

class array_stack{
    private:
    int arr[100];
    int top = -1;

    public:
    array_stack(){
        cout<<"stack has been intialised"<<endl ;
    }

    void push(int data){
        top++;
        arr[top] = data ;
    }

    int pop(){
        if(top == -1){
            return -1;
        }
        int x = arr[top];
        top--;
        return x ;
    }

    bool isempty(){
        return (top == -1);
    }

    int size(){
        if(top == -1){
            return 0 ;
        }
        return (top+1) ;
    }


    int gettop(){
        if(top == -1){
            return -1;
        }
        return (arr[top]);

    }


};

int main(){
    array_stack st;
    int arr[6] = {1,2,3,4,5,6} ;
    for(int i = 0;i<6;i++){
        st.push(arr[i]);
        cout<<arr[i]<<" is pushed into stack"<<endl ;
    }

    cout<<"Top value of stack ->"<<st.gettop()<<endl;
    cout<<"poped element : "<<st.pop()<<endl ;
    cout<<"poped element : "<<st.pop()<<endl ;
    cout<<"Top value of stack ->"<<st.gettop()<<endl;
    cout<<"size of the stack is : "<<st.size()<<endl ;

    return 0;
}