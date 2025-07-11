#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*
https://takeuforward.org/data-structure/implement-queue-using-stack/
*/
class queue1{
    private:
    stack<int>curr,temp ;
    //making push operation costly
    public:
    void push(int val){
        while(curr.size()!=0){
            temp.push(curr.top()) ;
            curr.pop() ;
        }
        curr.push(val) ;
        while(temp.size()!=0){
            curr.push(temp.top()) ;
            temp.pop() ;
        }
    }
    int pop(){
        if(curr.size() == 0)return -1 ;
        int x = curr.top() ;
        curr.pop() ;
        return x ;

    }

};
class queue2{
    private:
    stack<int>curr,temp ; 
    public:
    void push(int val){
        curr.push(val) ;
    }
    int pop(){
        if(curr.size() == 0)return -1 ;
        int x ; 
        while(curr.size()!=1){
            temp.push(curr.top()) ;
            curr.pop() ;
        }
        x = curr.top() ;
        curr.pop() ;
        while(temp.size()!=0){
            curr.push(temp.top()) ;
            temp.pop() ;
        }
        return x ;
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