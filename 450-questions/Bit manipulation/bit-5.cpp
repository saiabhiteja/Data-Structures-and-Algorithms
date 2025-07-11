#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int countsetbits(int num){
    int count = 0 ;
    while(num){
        num = num & num-1 ;
        count = count+1 ;
    }
    return count;
}
int main(){
    //checking a number is power of 2 or not
    int count1 = countsetbits(1);
  if(count1 == 1){
      cout<<"yes"<<endl ;
  }
  else{
      cout<<"No"<<endl;
  }
   
    return 0;
}