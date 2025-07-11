#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    finding sum of minimum ans maximum elements in subarrays of size k
    https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/
*/
vec maxs(vec arr,int k){
    //function for finding maximum element in subarray of size k
    //using deque
    deque<int> dq ;
    vec ans ;
    int i= 0,j = 0,n = arr.size() ;
    while(j<n){
        while(dq.size()!=0 && dq.back()<arr[j]){
            dq.pop_back() ;
        }
        dq.push_back(arr[j]) ;
        if((j-i+1) == k){
            ans.push_back(dq.front()) ;
            if(dq.front() == arr[i]){
                dq.pop_front() ;
            }
            i++;
        }
        j++;
    }
    return ans ;
    /*
    Time : O(N)
    Space : O(N)
    */

}
vec mins(vec arr,int k){
    //function for finding minimum element in subarray of size k
     deque<int> dq ;
    vec ans ;
    int i= 0,j = 0,n = arr.size() ;
    while(j<n){
        while(dq.size()!=0 && dq.back()>arr[j]){
            dq.pop_back() ;
        }
        dq.push_back(arr[j]) ;
        if((j-i+1) == k){
            ans.push_back(dq.front()) ;
            if(dq.front() == arr[i]){
                dq.pop_front() ;
            }
            i++;
        }
        j++;
    }
    return ans ;
    /*
    Time : O(N)
    Space : O(N)
    */
}
vector<int> sums(vec arr,int k){
    int n = arr.size() ;

    vec mini = mins(arr,k) ;
    vec maxi = maxs(arr,k) ;

    vec ans ;

    for(int i = 0;i<mini.size();i++){
        ans.push_back(mini[i]+maxi[i]) ;
    }

    return ans ;


}


int main() {

    vec arr = {2, 5, -1, 7, -3, -1, -2} ;
    vec ans = sums(arr,4) ;

    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}