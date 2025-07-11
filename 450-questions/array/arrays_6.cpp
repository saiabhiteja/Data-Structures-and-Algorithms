#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mod 1e9+7
#define fo(i,n) for(i = 0;i<n;i++)
void display(vec arr){
    int i = 0;
    fo(i,arr.size()){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
/*
    find union and intersection of two sorted arrays
*/
void method_1(vec arr1,vec arr2){
    vector<int> ans ;
    set<int> s ;
    for(int i: arr1){
        s.insert(i);
    }
    for(int i: arr2){
        s.insert(i);
    }
    for(auto it : s){
        ans.push_back(it);
    }
    cout<<"union"<<endl;
    display(ans);

    //intersection
    map<int,int> mp; 
    for(int i: arr1){
        mp[i]++;
    }
    vec ans2 ;
    for(int i: arr2){
        if(mp[i]){
            ans2.push_back(i);
        }
    }
    cout<<"Intersection : "<<endl;
    display(ans2);
    /*
    Time : O((n+m)*log(n+m))
    Space : O(n+m)
    */

}
void method_2(vec arr1,vec arr2){
    //using merge sort
    int i = 0;
    int j = 0;
    int n = arr1.size() ;
    int m = arr2.size() ;
    vec ans1,ans2 ;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            ans1.push_back(arr1[i]);
            i++;
        }
        else if (arr2[j]<arr1[i]){
            ans1.push_back(arr2[j]);
            j++;
        }
        else{
            ans1.push_back(arr1[i]);
            ans2.push_back(arr2[j]);
            i++;
            j++;
        }
    }
    while(i<n){
        ans1.push_back(arr1[i++]);
    }
    while(j<m){
        ans1.push_back(arr2[j++]) ;
    }

    cout<<"union"<<endl;
    display(ans1);
    cout<<"Intersection : "<<endl;
    display(ans2);

    /*
    Time : O(N+M)
    Space : O(1) //not considering ans1,ans2
    */


}
int main() {
    vec arr1 = {1,2,3,4,5};
    vec arr2 = {1,2,4,6};
    method_2(arr1,arr2);
return 0;
}