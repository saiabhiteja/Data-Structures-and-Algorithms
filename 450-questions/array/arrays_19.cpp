#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    finding common elements in 3 arrays 
*/
vector<int> intersection(vector<int> arr1,vector<int> arr2,int n,int m){
        int i = 0;
        int j = 0;
        vector<int> ans  ;
        while(i<n && j<m){
            if(arr1[i]<arr2[j]){
                i++;
            }
            else if(arr1[i]>arr2[j]){
                j++;
            }
            else{
                ans.push_back(arr1[i]);
                while(i<n && j<m && arr1[i] == arr2[j])i++;j++;
            }
        }
        return ans;
        /*
        Time : O(min(n,m))
        Space : O(min(n,m))
        */
        
    }

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
          vector<int> arr1,arr2,arr3,ans ;
          for(int i = 0;i<n1;i++){
              arr1.push_back(A[i]);
          }
          for(int i = 0;i<n2;i++){
              arr2.push_back(B[i]);
          }
          for(int i = 0;i<n3;i++){
              arr3.push_back(C[i]);
          }
          
          ans = intersection(arr1,arr2,n1,n2) ;
          //cout<<ans.size();
          ans = intersection(ans,arr3,ans.size(),n3);
          return ans ;
          /*
          Time : O(n1+n2+n3)
          space: O(n1+n2+n3)
          */
          
    }
int main() {
/**/
return 0;
}