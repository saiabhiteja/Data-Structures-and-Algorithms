#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
https://takeuforward.org/data-structure/length-of-longest-substring-without-any-repeating-character/
*/
int method1(string s){
    int ans = 0 ;
    int n = s.size() ;
    for(int i = 0;i<n;i++){
        unordered_map<char,int> mp ;
        string tmp = "" ;
        for(int j = i;j<n;j++){
            mp[s[j]]++ ;
            tmp.push_back(s[j]) ;
            if(tmp.size() == mp.size()){
                ans = max(ans,j-i+1);
            }
        }
    }
    return ans ;
    /*
    Time : O(N)
    space : O(N)
    */
}
int method2(string s){
    int i = 0;
    int j = 0;
    int n = s.size() ;
    int ans = 0 ;
    unordered_map<char,int> mp;
    while(j<n){
        mp[s[j]]++ ;
        if(mp.size() == (j-i+1)){
            ans = max(ans,(j-i+1)) ;
        }
        else if(mp.size()<(j-i+1)){
            while(mp.size()<(j-i+1)){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]) ;
                }
                i++ ;
            }
            if(mp.size() == (j=i+1)){
                ans = max(ans,(j-i+1)) ;
            }
        }
        j++ ;
    }
    return ans ;
    /*
    Time : O(N)
    space : O(N)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}