#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    Smallest range in K lists
    https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1
*/
#define N 1000
pair<int,int> findSmallestRange(int arr[][N], int n, int k){
        
        pair<int,int> p1 ;
        p1 = {INT_MAX,INT_MIN} ; //for storing maximum and minimum values
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq ;
        //value,row,index

        for(int i = 0;i<k;i++){
            pq.push({arr[i][0],{i,0}}) ;
            p1.first = min(p1.first,arr[i][0]);
            p1.second = max(p1.second,arr[i][0]);
        }

        int range = p1.second-p1.first ; //current range
        int curr_max = p1.second ; //present maximum

        while(pq.size()!=0){

            auto t = pq.top() ;
            pq.pop() ;

            int curr_min = t.first ; //since min heap

            int curr_range = curr_max - curr_min ;

            if(curr_range < range){
                //only if it is less than our range
                range = curr_range ;
                p1.first = curr_min ;
                p1.second  = curr_max;
            }

            int curr_row = t.second.first ;

            int curr_row_index = t.second.second ;

            curr_row_index++;

            if(curr_row_index<n){
                curr_max = max(curr_max,arr[curr_row][curr_row_index]);
                pq.push({arr[curr_row][curr_row_index],{curr_row,curr_row_index}});
            }
            else{
                break;
            }
            
        }
        return p1;
        /*
        Time : O(n*k*log(k))
        space : O(k)
        */
    }
int main() {
    
    return 0;
}