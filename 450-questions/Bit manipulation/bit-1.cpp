#include<iostream>
using namespace std;
int countsetbits(int num){
    int count = 0 ;
    while(num){
        num = num & num-1 ;
        count = count+1 ;
    }
    return count;
}
int count_setbits_2(int num){
    int count = 0;
    while(num){
        if((num & 1)==1){
            count++;
        }
        num = num>>1;
    }
    return count; 
}
int main(){
    cout<<countsetbits(15)<<endl;
    cout<<count_setbits_2(15)<<endl;
    return 0;
}