#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
----pascals triangle
  --create a vector of vectors ans 
  --for each row intialise all elements of size(i+1) with 1
  --except first and last element of current element update all other elements 
  --tmp[j] = ans[i-1][j]+ans[i-1][j-1]
*/
vector<vector<int>> generate(int numrows) {
     vector<vector<int>> ans;
        if(numrows<=0)
            return ans;
        for(int i = 0;i<numrows;i++){
            vector<int> temp(i+1,0) ;
            for(int j = 0;j<i+1;j++){
                if(j==0 || j==i){
                    temp[j] = 1;
                }
                else{
                    temp[j] = ans[i-1][j]+ans[i-1][j-1];
                }
            }
            ans.push_back(temp);
        }
        return ans ;
        /*
        Time : O(numrows*numrows)
        space : O(1)
        */
        
    }
vector<vector<int>> generate(int numrows) {
     vector<vector<int>> ans;
        if(numrows<=0)
            return ans;
        for(int i = 0;i<numrows;i++){
            vector<int> temp(i+1,1) ;
            for(int j = 1;j<i;j++){
                
                    temp[j] = ans[i-1][j]+ans[i-1][j-1];
                
            }
            ans.push_back(temp);
        }
        return ans ;

        /*
        Time :O(N^2)
        space : o(1)
        */
        
    }


int main() {

ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}