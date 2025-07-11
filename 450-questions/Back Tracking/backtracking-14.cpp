#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    permutation of string
*/
void helper(vector<int> freq,string temp,vector<string>& ans,string s){
        if(temp.size() == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0;i<s.size();i++){
            if(freq[i] == 0){
                freq[i] = 1;
                temp.push_back(s[i]);
                helper(freq,temp,ans,s);
                temp.pop_back();
                freq[i] = 0;
            }
        }
    }

vector<string>find_permutation(string s)
		{
		    vector<string> ans ;
		    int n = s.size();
		    vector<int> freq(n,0) ;
		    sort(s.begin(),s.end());
		    helper(freq,"",ans,s);
		    return ans ;
            /*
            Time : O(n!*n)
            Space : O(n)
            */
		}
int main() {
    vector<string> ans = find_permutation("sai") ;
    for(auto it : ans){
        cout<<it<<endl;
    }
    return 0;
}