#include "bits/stdc++.h"
using namespace std ;
class array_queue{
    private:
    int arr[100];
    int back = -1;
    int front = -1;
    public:
    array_queue(){
        cout<<"Queue is being instalisied"<<endl ;
    }
    void push(int data){
        if(front == -1){
            back++;
        }

        front++;
        arr[front] = data ;
    }

    bool isempty(){
        return (front == -1 && back>front) ;
    }

    int pop(){
        if(front == -1 && back>front){
            return -1;
        }
        int x = arr[back];
         back++;
        return x ;
    }

    int size(){
        if(front == -1 && back>front){
            return 0;
        }
        return front-back+1 ;

    }

    int get_front(){
        if(front == -1 && back>front){
            return -1;
        }
        return arr[back];

    }


};
int main(){
    array_queue q;
    int arr[6] = {1,2,3,4,5,6} ;
    for(int i = 0;i<6;i++){
        q.push(arr[i]);
        cout<<arr[i]<<" is pushed into queue"<<endl ;
    }

    cout<<"Top value of queue ->"<<q.get_front()<<endl;
    cout<<"poped element : "<<q.pop()<<endl ;
    cout<<"poped element : "<<q.pop()<<endl ;
    cout<<"Top value of queue ->"<<q.get_front()<<endl;
    cout<<"size of the queue is : "<<q.size()<<endl ;
    if(q.isempty()){
        cout<<"q is  empty"<<endl;
    }
    else{
        cout<<"q is not empty"<<endl ;
    }
    return 0;
}