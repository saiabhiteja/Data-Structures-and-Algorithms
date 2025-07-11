#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    palindromic partions
*/

bool ispalindrome(string s){
    int low = 0;
    int high = s.size()-1;
    while(low<=high){
        if(s[low]!=s[high]){
            return false;
        }
        low++;
        high--;
    }
    return true;
}

void helper(int ind,string s,vector<vector<string>>& ans,vector<string> temp){
    if(ind == s.size()){
        ans.push_back(temp);
        return;
    }
    string temp_s  = "";
    for(int i = ind;i<s.size();i++){
        temp_s.push_back(s[i]);
        if(ispalindrome(temp_s)){
            temp.push_back(temp_s);
            helper(i+1,s,ans,temp);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partions(string s){
    vector<vector<string>> ans ;
    helper(0,s,ans,{});
    return ans ;
    /*
    Time : O(2^N)
    Space : O(N^2)
    */
}
int main() {
    vector<vector<string>> ans = partions("nitin") ;
    for(auto it: ans){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}