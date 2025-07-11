#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    finding wether given set2 is subset of s1 or not
*/
bool issubset(vector<int> arr1,vector<int> arr2){
    //large is arr1 
    sort(arr1.begin(),arr1.end()) ;
    //using binary_search
    for(int i: arr2){
        if(!binary_search(arr1.begin(),arr1.end(),i)){
            return false;
        }
    }
    return true;
    /*
    Time : O(Nlogn) + O(MlogN)
    Space : O(1)
    */
}
bool issubset_2(vector<int> arr1,vector<int> arr2){
    //using unodred map
    unordered_map<int,int> mp ;
    for(int i: arr1){
        mp[i]++;
    }

    for(int i:arr2){
        if(mp.find(i) == mp.end()){
            return false;
        }
    }
    return true;
    /*
    Time : O(N)+O(M)
    Space: O(N)

    */
}
int main() {
    vector<int> arr1 = {1,3,4,5,2,4,7} ;
    vector<int> arr2 = {1,3,5,7} ;
    if(issubset_2(arr1,arr2)){
        cout<<" yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}