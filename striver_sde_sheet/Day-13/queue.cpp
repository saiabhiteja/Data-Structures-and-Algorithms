#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*
https://takeuforward.org/data-structure/implement-queue-using-array/
*/
class queue{
    private:
    vector<int> arr ;
    int front,back ;
    int currsize,maxsize ;
    public:
    queue(int size){
        arr = vector<int>(size,0) ;
        front = -1 ;
        back = -1;
        currsize = 0 ;
        maxsize = size ;
    }
    void push(int val){
        if(currsize == arr.size()){
            cout<<"Queue Over Flow"<<endl ;
            return ;
        }
        if(back == -1){
            front = 0 ;
            back = 0 ;
        }
        else{
            back = (back+1)%maxsize ;

        }
        arr[back] = val ;
        currsize++ ;
    }
    int pop(){

        if(front == -1){
            cout<<"Empty Queue"<<endl ;
            return ;
        }

        int x = arr[front] ;
        if(currsize == 1){
            front = -1 ;
            back = -1 ;
        }
        else{
            front = (front+1)%maxsize  ;
        }
        currsize-- ;
        return x ;


    }
    int front(){
        if(front == -1){
            return -1 ;
        }
        return arr[front] ;
    }
    int size(){
        return currsize ;
    }
    bool isempty(){
        return currsize == 0 ;
    }
};
void solve(){
    int n ; 
    cin>>n ;
    vector<int> arr(n,0) ;
    for(int i = 0;i<n;i++){
        cin>>arr[i] ;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    int t ;
    cin>>t ;
    while(t){
        solve() ;
        t--;
    }

    return 0 ;
}