#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*
https://takeuforward.org/data-structure/implement-stack-using-array/
*/
class stack{
    private:
    vector<int>arr ;
    int top ;
    public:
    stack(int size){
        arr = vector<int>(size,0) ;
        top = -1 ;
    }

    void push(int val){
        if(top>= arr.size()){
            cout<<"Stack Over Flow"<<endl ;
        }
        top++ ;
        arr[top] = val ;
    }

    int pop(){
        if(top == -1){
            return -1 ;
        }
        int x = arr[top] ;
        arr[top] = 0 ;
        top-- ;
        return x ;
    }

    int peek(){
        if(top == -1){
            return -1 ;
        }
        return arr[top] ;
    }

    int size(){
        return top+1 ;
    }

    bool isempty(){
        return (top+1 == 0) ;
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