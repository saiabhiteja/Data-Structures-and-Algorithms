#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    finding triplet that which will be equal to given target
*/
bool find3Numbers(int A[], int n, int X)
    {
        if(n<=2){
            return 0;
        }
        sort(A,A+n);
        for(int i = 0;i<n-2;i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = A[i]+A[j]+A[k];
                if(sum == X){
                    return 1;
                }
                else if(sum>X){
                    k--;
                }
                else{
                    j++;
                }
                
            }
        }
        return 0;

        /*
        Modified two pointer approach
        Time : O(N^2)
        Space : O(1)
        */
        
    }
int main() {
    int A[6] = {1, 4, 45, 6, 10, 8};
    if(find3Numbers(A,6,50)){
        cout<<"can can"<<endl;
    }
    else{
        cout<<" No"<<endl;
    }
    return 0;
}