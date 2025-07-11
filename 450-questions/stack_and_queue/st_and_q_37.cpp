#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    First non-repeating character in a stream 
    https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
*/
string frc(string s){
    
    int len = s.size() ;
    queue<char> q ;
    int hsh[26] = {0};
    for(int i = 0;i<len;i++){
        hsh[s[i]-'a']++;
        if(hsh[s[i]-'a'] == 1){
            q.push(s[i]);
        }
        while(q.size()!=0 && hsh[q.front()-'a']!=1){
            q.pop();
        }
        if(q.size() == 0){
            s[i] = '#';
        }
        else{
            s[i] = q.front();
        }

    }
    return s ;
    /*
    Time : O(N)
    Space : O(N)
    */
}
int main() {
    cout<<frc("aabc")<<endl;
    return 0;
}