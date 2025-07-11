#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*
https://takeuforward.org/data-structure/next-greater-element-using-stack/
*/

vector<int> method1(vector<int>& nums){
    //one method we can 0 to n-2 elements to back so that we can get circular 
    //array condition
    int n = nums.size() ;
    for(int i = 0;i<(n-2);i++){
        nums.push_back(nums[i]) ;
        //circular aray done
    }

    stack<int> st ; 
    vector<int> ans(n,0) ;
    for(int i = nums.size()-1;i>=0;i--){
        int curr_ans = -1 ;
        if(st.size() == 0){curr_ans = -1 ; }
        else if(st.size()>0 && st.top()>nums[i]){curr_ans = st.top() ;}
        else{
            while(st.size() && st.top()<=nums[i]){
                st.pop() ;
            }
            if(st.size() == 0){curr_ans = -1;}
            else curr_ans = st.top() ;
        }
        if(i<n)ans[i] = curr_ans ;
        st.push(nums[i]) ;

    }
    return ans ;
    /*
    Time : O(N)
    space : O(N)
    */

}

vector<int> method2(vector<int>& nums){
    //one method we can 0 to n-2 elements to back so that we can get circular 
    //array condition
    // without resizing the array
    int n = nums.size() ;
    // for(int i = 0;i<(n-2);i++){
    //     nums.push_back(nums[i]) ;
    //     //circular aray done
    // }

    stack<int> st ; 
    vector<int> ans(n,0) ;
    for(int i = 2*n-1;i>=0;i--){
        int curr_ans = -1 ;
        if(st.size() == 0){curr_ans = -1 ; }
        else if(st.size()>0 && st.top()>nums[i%n]){curr_ans = st.top() ;}
        else{
            while(st.size() && st.top()<=nums[i%n]){
                st.pop() ;
            }
            if(st.size() == 0){curr_ans = -1;}
            else curr_ans = st.top();
        }
        if(i<n)ans[i] = curr_ans ;
        st.push(nums[i%n]) ;

    }
    return ans ;
    /*
    Time : O(N)
    space : O(1)
    */

}

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