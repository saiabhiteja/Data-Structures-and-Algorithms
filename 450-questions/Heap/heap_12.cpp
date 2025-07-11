#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    finding median of running stream of numbers
    https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1
*/
class Solution
{
    public:
    //Function to insert heap.
    
        priority_queue<int> pq_max;
        priority_queue<int,vector<int>,greater<int>>pq_min ;
    
    void insertHeap(int &x)
    {
        if(pq_max.size() == 0 || pq_max.top()>x){
            pq_max.push(x);
        }
        else{
            pq_min.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        //which ever is having greater size pop 1 and push 1 into lesser size one
        if(pq_max.size()>pq_min.size()+1){

            pq_min.push(pq_max.top());
            pq_max.pop();
        }
        else if(pq_min.size()>pq_max.size()+1){

            pq_max.push(pq_min.top());
            pq_min.pop();
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
     double ans = 0;
        if(pq_max.size() == pq_min.size()){
            //even number condition
            ans = (double)pq_max.top()+(double)pq_min.top();
            ans = ans/2 ;
        }
        else{
            //odd number conditions
            if(pq_max.size()>pq_min.size()){
                ans = (double)pq_max.top();
            }
            else{
                ans = (double)pq_min.top();
            }
        }
        return ans;
    }
};
int main() {
return 0;
}