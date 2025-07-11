#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    Reorganize String
    https://leetcode.com/problems/reorganize-string/
*/
#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
    rearrange the string

*/
string rearrange(string s){
    map<char,int> mp ;
    for(char ch : s){
        mp[ch]++;
    }

    priority_queue<pair<int,char>> pq ;

    for(auto it: mp){
        pq.push({it.second,it.first}) ;
    }

    string ans = "" ;
    auto block = pq.top() ;
    pq.pop() ;

    ans.push_back(block.second) ;
    block.first--;

    while(pq.size()!=0){
        auto temp = pq.top();
        pq.pop() ;
        ans.push_back(temp.second) ;
        temp.first--;
        if(block.first>0){
            pq.push(block) ;
        }
        block = temp ; //since both characters should not be same
    }

    if(block.first){
        return "" ;
    }

    return ans ;

    /*
    Time : O(NlogN)
    Space : O(N)
    */

}
int main() {
    cout<<rearrange("aabbcc")<<endl;
    return 0;
}

