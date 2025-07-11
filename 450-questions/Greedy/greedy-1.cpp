#include "bits/stdc++.h"
#include <iostream>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int>p2){
    return (p2.second>p1.second) ;
}
int maxMeetings(int start[], int end[], int n)
   {
       vector<pair<int,int>>temp;
       for(int i=0;i<n;i++){
           pair<int,int>p;
           p.first= start[i];
           p.second=end[i];
           temp.push_back(p);
       }
       int meetings=1;
       //1->sorting..
       sort(temp.begin(),temp.end(),compare);
       int a =temp[0].second;

       //2->traversal
       for(int i=1;i<n;i++){
           if(a<temp[i].first){
               meetings++;
               a= temp[i].second;
           }
       }
       
       return  meetings;
   }
int main(){
    int start[] = {10, 12, 20};
    int end[] = {20, 25, 30};
    cout<<maxMeetings(start,end,3);
    return 0;
}