#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int countBitsFlip(int a, int b){
        a = a^b ;
        int count = 0;
        while(a){
            count++;
            a = a & (a-1);
        }
        return count ;
        
    }

int main(){
    cout<<countBitsFlip(10,20);
    return 0;
}