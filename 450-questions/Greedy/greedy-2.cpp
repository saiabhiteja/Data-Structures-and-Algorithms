#include <iostream>
#include "bits/stdc++.h"
using namespace std;
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
bool compare(Job j1,Job j2){
        return (j1.profit>j2.profit);
    }
vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> ans;
        int profit = 0;
        int count = 0;
        sort(arr,arr+n,compare);
        bool status[101];
        for(int i = 0;i<=100;i++){
            status[i] = 0;
        }
        for(int i = 0;i<n;i++){
            for(int j = min(100,arr[i].dead)-1;j>=0;j--){
                if(status[j] == false){
                    status[j] = true;
                    count++;
                    profit = profit+arr[i].profit;
                    break;
                }
            }
        }
        ans.push_back(count);
        ans.push_back(profit);
        return ans;
       
    }
int main(){
    Job arr[] = {{1,4,20},{2,1,10},{3,1,40},{4,1,30}};
    vector<int> ans = JobScheduling(arr,4);
    cout<<"Number of Jobs : "<<ans[0]<<endl;
    cout<<"Profit = "<<ans[1]<<endl ;

    return 0;
}