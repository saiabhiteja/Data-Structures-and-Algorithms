#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    circular tour
    https://practice.geeksforgeeks.org/problems/circular-tour/1
*/
bool ispossible(vec pet,vec dis,int ind){
    int n = pet.size() ;
    int curr_dis = dis[ind] ;
    int curr_pet = pet[ind] ;
    int pos = ind ;
    ind++ ;
    if(ind == n){ind = 0;}
    while(pos!=ind){
        if((curr_pet-curr_dis)>=0){
            curr_pet = curr_pet-curr_dis ;
            curr_pet +=pet[ind] ;
            curr_dis = dis[ind] ;
        }
        else{
            return false;
        }
        ind++ ;
        ind = ind%n ;
        //cout<<ind<<endl;
    }
    if((curr_pet -curr_dis)>=0)
    return true; 
    return false;
    /*
    Time : O(N)
    Space : O(1)
    */
}
int method_1(vector<int> pet,vector<int> dis){
    //i will try checking from all positions where ever i found it suitable 
    //then i will return it
    int n = pet.size() ;
    for(int i = 0;i<n;i++){
        if(ispossible(pet,dis,i)){
            return i;
        }
    }
    return -1;
    /*
    Time : O(N*N)
    SPace : O(1)
    */
}
int method_2(vec pet,vec dis){
    int fuel_req = 0; //total fuel req among total tour
    int curr_fuel = 0;
    int n = pet.size() ;
    int strt = 0;
    for(int i = 0;i<n;i++){
        int curr = pet[i] - dis[i] ;
        curr_fuel += curr ;
        if(curr_fuel<0){
            curr_fuel = 0;
            strt = i+1;
        }
        fuel_req += curr ;
    }
    if(fuel_req >=0){
        return strt;
    }
    return-1;
    /*
    Time : O(N)
    SPace : O(1)
    */
}
/*
//wrong 
int method_3(vec pet,vec dis){
    vec temp ;
    int n = pet.size();
    for(int i = 0;i<n;i++){
        temp.push_back(pet[i]-dis[i]) ;
    }
    vec suffix(n),prefix(n) ;
    prefix[0] = temp[0] ;
    for(int i = 1;i<n;i++){
        prefix[i] = temp[i]+prefix[i-1] ;
    }
    suffix[n-1] = temp[n-1] ;
    for(int i = n-2;i>=0;i--){
        suffix[i] = temp[i]+suffix[i+1] ;
    }

    for(int i = 0;i<n;i++){
        if(temp[i]>=0 &&(prefix[i]+suffix[i]-2*temp[i])>=0){
            return i ;
        }
    }
    return -1;}
    
    Time : O(N)
    Space : O(N)
*/

    

int main() {
    vec pet = {4,6,7,4} ;
    vec dis = {6,5,3,5} ;
    cout<<method_2(pet,dis)<<endl;
    return 0;
}