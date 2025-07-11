#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
--sort an array of 0's ,1's and 2's
--sorting (nlogn)
--counting number of ones ,twos,zeroes and pushing them
-- ducth national Flag algo
*/
void dutch_national_algo(int arr[],int n){
    /*
         arr partioned into 4 sections
         1. 0 to low-1 -> 0s
         2.low to mid ->1s
         3.mid to high-1 ->unknow section
         4.high-1 to N ->2s
    */
    int low = 0;
    int mid = 0;
    int high = n-1 ;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low++],arr[mid++]);
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high--]);
        }
    }
    /*
    Time : O(N)
    Space : O(1)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}