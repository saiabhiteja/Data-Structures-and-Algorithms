#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int square(int num){
    //square of num without using * / %
    //simply adding num num times;
    if(num<0){
        num = abs(num);
    }
    int ans = 0;
    int i = num;
    while(i){
        ans = ans+num ;
        i--;
    }
    return ans;
}
int square_with_bits(int num){
    if (num == 0)
        return 0;
    if(num<0){
        num = abs(num);
    }
    
     int x = num >> 1;

    /*
        if n is even 
            square(n) = 4*square(n/2) 
        if n is odd
            square(n) = 4*square(floor(n/2)) + 4*floor(n/2) + 1 

    */
 
   
    if (num & 1)
        return ((square_with_bits(x) << 2) + (x << 2) + 1);
    else 
        return (square_with_bits(x) << 2);

}
int main(){
    cout<<square_with_bits(5)<<endl;
    cout<<square(4)<<endl;
    return 0;
}