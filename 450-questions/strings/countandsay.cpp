#include <iostream>
using namespace std;
#include "bits/stdc++.h"

class Solution {
public:
    string countAndSay(int n) {
        if (n==1)
        {
            return ("1");
        }
        else{
            string k = countAndSay(n-1);
            string s;
            s.clear();
            int len = k.length();
            int i =0;
            while(i<len){
                char x = k[i];
                int count = 0;
                int j =i;
                while(k[j]==k[j+1] && j<len && len>1){
                    count = count+1 ;
                    j = j+1;
                }
                if (count==0)
                {
                    s = s+'1'+x ; 
                    i = i+1 ;
                }
                else
                {
                    stringstream a;
                    string a1;
                    a<<(count+1);
                    a>>a1;
                    s = s + a1+x ;
                    i = i+count+1 ;
                }

            }
            return s;

        }
    }
};

int main(){
    int n = 5;
    Solution s ;
    string x = s.countAndSay(n);
    cout<<x<<endl ;

}