#include<iostream>
#include "bits/stdc++.h"
using namespace std;
int countsetbits(int num){
    int count = 0 ;
    while(num){
        num = num & num-1 ;
        count = count+1 ;
    }
    return count;
    /*
    using this function for total setbits
    Time complexity : O(Nlog(n))
    Space complexity : O(1)
    */
}

int main(){
    int su = 0;
    for(int i = 1; i<=25;i++){
        su = su+countsetbits(i);
    }
    cout<<su<<endl;
    return 0;
}