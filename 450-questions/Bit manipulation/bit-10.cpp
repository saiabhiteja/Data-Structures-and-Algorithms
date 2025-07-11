#include <iostream>
#include "bits/stdc++.h"
using namespace std;
/*
we can do this problem using recu
*/
vector<string> AllPossibleStrings(string s){
		    int mask=(1<<(s.length()))-1;
		  int mask_length=s.length();
		  vector<string> ans;
		  for(int i=0;i<=mask;i++){
		      string str;
		      for(int j=0;j<mask_length;j++){
		          if(i&(1<<j)){
		              //checking jth bit of ith mask
		              str=str+s[j];
		          }
		      }
		      ans.push_back(str);
		  }
		  ans.erase(ans.begin()); //removing empty string
		  sort(ans.begin(),ans.end());
		  return ans;
}
int main(){
    vector<string> ans = AllPossibleStrings("abc");
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}