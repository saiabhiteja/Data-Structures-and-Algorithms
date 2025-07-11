#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers
     https://practice.geeksforgeeks.org/problems/minimum-sum4058/1
*/
string add(string num1,string num2){

    if(num1.length()>num2.length()){
        //just making num2 as greater length
        swap(num1,num2) ;
    }
    string ans = "" ;
    int l1 = num1.length(),l2 = num2.length() ;
    reverse(num1.begin(),num1.end()) ;
    reverse(num2.begin(),num2.end()) ;

    int carry = 0;
    for(int i = 0;i<l1;i++){
        int sum = ((num1[i]-'0')+(num2[i]-'0')+carry) ;
        ans.push_back((sum%10)+'0') ;
        carry = sum/10 ;
    }
    for(int i = l1;i<l2;i++){
        int sum = ((num2[i]-'0')+carry) ;
        ans.push_back((sum%10)+'0') ;
        carry = sum/10 ;
    }
    if(carry){
        ans.push_back(carry+'0') ;
    }
    reverse(ans.begin(),ans.end());

    //for removing leading zeroes
    int n = ans.size(),i=0;
    while(i<n && ans[i] == '0') i++;
    ans.erase(ans.begin(),ans.begin()+i) ;


    return ans ;

}
string solve(vec arr,int n){
    priority_queue<int,vector<int>,greater<int>> pq ;
    for(int i = 0;i<n;i++){
        pq.push(arr[i]) ;
    }

    string num1,num2 ;
    while(pq.size()!=0){
        int x1 = pq.top() ;
        pq.pop() ;
        num1.push_back(x1+'0') ;
        if(pq.size()){
            int x2 = pq.top() ;
            pq.pop() ;
            num2.push_back(x2+'0') ;
        }
        else{
            break ;
        }
    }
    //same can be done by sorting as well 
    string ans = add(num1,num2) ;
    return ans ;
    /*
    Time : O(NlogN)
    Space :O(N)
    */
}
int main() {
    vec arr = {6, 8, 4, 5, 2, 3} ;
    cout<<solve(arr,arr.size()) ;
    return 0;
}