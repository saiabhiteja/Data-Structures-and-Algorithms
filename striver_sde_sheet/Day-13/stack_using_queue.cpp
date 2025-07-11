#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*
https://takeuforward.org/data-structure/implement-stack-using-single-queue/
*/
class stack{
    private:
    queue<int>q ;
    public :
    void push(int val){
        int curr = q.size() ;
        q.push(val) ;
        for(int i = 0;i<curr;i++){
            int x = q.front() ;
            q.pop() ;
            q.push(x) ;
        }
    }

    int pop() {
        if(q.size() == 0)return -1 ;
        int x = q.front() ;
        q.pop() ;
        return x ;
    }

    int size(){
        return (int)q.size() ;
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