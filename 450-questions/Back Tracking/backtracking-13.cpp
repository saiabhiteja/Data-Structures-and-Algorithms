#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    finding maximum number by doing atmost kswaps
*/
void helper(string s,string& ans,int k,int n,int ind){
        //base
        if(k == 0 || ind == n){
            if(s>ans){
                ans = s ;
            }
            return ;
        }
        if(s>ans){
            ans = s ;
        }
        for(int i = ind ;i<(n-1);i++ ){
            char chi = s[i] ;
            for(int j = i+1;j<n;j++){
                char chj = s[j] ;
                if(chj>chi){
                    swap(s[i],s[j]);
                    helper(s,ans,k-1,n,i+1);
                    swap(s[i],s[j]);
                }
            }
        }
    }

string findMaximumNum(string str, int k)
    {
        string ans = str;
        helper(str,ans,k,str.length(),0);
        return ans ;
       /*
       Time : O(n!/(n-k)!)
       SPace : O(n)
       */
    }
int main() {
    cout<<findMaximumNum("12357",3);

    return 0;
}