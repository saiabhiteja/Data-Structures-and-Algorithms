#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    finding longest consecutive subsequence
*/
int findLongestConseqSubseq(int arr[], int n)
    {
        vector<int> count(100001,0) ; //for storing freq
        
        for(int i = 0;i<n;i++){
            count[arr[i]]++;
        }

        int ans = 0;

        for(int i = 0;i<=100000;i++){
            int tmp = 0;
            if(count[i]>0){
                while(i<=100000 && count[i]>0){
                    tmp++;
                    i++;
                }
            }
            ans = max(ans,tmp) ;
        }
        return ans ;
        /*
        Time : O(N)
        space : O(N)
        */
}
int main() {
    int arr[7] = {2,6,1,9,4,5,3} ;
    cout<<findLongestConseqSubseq(arr,7)<<endl;
    return 0;
}