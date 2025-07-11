#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    implementing circular queue
    https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/


    Applications: 
 

Memory Management: The unused memory locations in the case of ordinary queues can be utilized in circular queues.
Traffic system: In computer controlled traffic system, circular queues are used to switch on the traffic lights one by one repeatedly as per the time set.
CPU Scheduling: Operating systems often maintain a queue of processes that are ready to execute or that are waiting for a particular event to occur.
*/
class circular_queue{
    private:
    vec nums ;
    int front,rear ,size;

    bool isfull(){
        //function for checking wether queue is full or not
        if(front == 0 && rear == size-1 || rear == (front-1)%(size)){
            return true;
        }
        return false;
    }

    bool isempty(){
        //function for checking wether queue has elements or not
        return ( front == -1) ;
    }
    public:
    circular_queue(int size){
        this->nums = vector<int>(size,0) ;
        this->front = -1;
        this->rear = -1;
        this->size = size ;
    }

    void enqueue(int data){
        //function for inserting
        //check full condition
        if(isfull()){
            cout<<"Queue is Full SO No more Insertions "<<endl;
        }
        else{
            cout<<data<<" : inserted"<<endl;
            if(front == -1){
                //insertion of first element
                front = rear = 0;
                nums[rear] = data ;
            }
            else{
                //inserting at a position
                rear++ ;
                rear = (rear)%(size) ;
                nums[rear] = data ;
            }
        }

    }

    void dequeue(){
        //function for deleting
        //checking wether queue is empty
        if(isempty()){
            cout<<"you cannot pop element "<<endl;
            front = -1;
            rear = -1;
        }
        else{
            cout<<nums[front]<<": poped"<<endl;
            front = (front+1)%(size) ;
        }

    }

    int front_(){

        if(isempty()){
            return -1;
        }
        return nums[front] ;

    }

    int rear_(){

        if(isempty()){
            return -1;
        }
        
        return nums[rear] ;

    }

    void dispaly(){
        if(isempty()){
            cout<<"queue is empty "<<endl;
        }
        else{
            if(rear>front){
                for(int i = front ;i<=rear;i++){
                    cout<<nums[i]<<" ";
                }
                cout<<endl;
            }
            else{
                for(int i = front;i<size;i++){
                    cout<<nums[i]<<" ";
                }
                for(int i = 0;i<=rear;i++){
                    cout<<nums[i]<<" ";
                }
                cout<<endl;
            }
        }
    }

};
int main() {

    circular_queue cq(5) ;

    cq.enqueue(14) ;
    cq.enqueue(22) ;
    cq.enqueue(13) ;
    cq.enqueue(-6) ;
    cq.dispaly() ;
    cq.dequeue() ;
    cq.dequeue() ;
    cq.dispaly() ;
    cq.enqueue(9) ;
    cq.enqueue(20) ;
    cq.enqueue(5) ;
    cq.dispaly();
    cq.enqueue(10);
    cq.front_() ;




    return 0;
}