#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*
    word break problem 
    Given string without spaces and dictonary find possible sentence 
*/
unordered_map<string,bool> mp ;
void helper(string s,string temp,vector<string>& ans){
    if(s.length() == 0){
        temp.pop_back();
        ans.push_back(temp) ;
        return ;
    }

    for(int i = 0;i<s.length();i++){
        string left = s.substr(0,i+1) ;
        if(mp[left]){
            string right = s.substr(i+1) ;
            left.push_back(' ') ;
            helper(right,temp+left,ans) ;
        }
    }

}
vector<string> wordBreak(int n, vector<string>& dict, string s){
        vector<string> ans ;
        for(int i = 0;i<n;i++){
            mp[dict[i]] = true ;
        }
        helper(s,"",ans);
        return ans;
        /*
        Time : 
        Space : O(N) + O(N)
        */
        
}    
int main() {
        vector<string> dict = {"cats", "cat", "and", "sand", "dog"};
        vector<string>ans =  wordBreak(dict.size(),dict, "catsanddog") ;
        for(auto it: ans){
            cout<<it<<endl;
        }

    return 0;
}