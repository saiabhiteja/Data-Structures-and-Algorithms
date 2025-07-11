#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int setbit(int num , int pos){
    //1 = 0001
    return (num | (1<<(pos-1)));
}

//getbit function
int getbit(int num,int pos){
    //5 binary = 0101 if i want to get 2 nd position and with 0010
    return (num & (1<<(pos-1))) ;
}
int setSetBit(int x, int y, int l, int r){
       for(int i = l;i<=r;i++){
           if(getbit(y,i)){
               x = setbit(x,i);
           }
       }
       return x;
    }
int main(){
    cout<<setSetBit(44,3,1,5)<<endl;
    return 0;
}