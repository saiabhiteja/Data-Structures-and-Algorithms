#include <iostream>
#include "bits/stdc++.h"
using namespace std;
//division of two numbers without using division,multipication and mod operator
int division(int num1,int num2){
    bool sign;
    /*
    when num1 >0 ,num2 >0 quotient sign is postive
    2-> num1 >0 ,num2<0 ,for getting a postive answer 
    we have to multiply num2 with negative number (-*+ = -)
    so quoitent will be negative
    3-> same when num1<0 and num1>0
    4-> both are negative then no need of sign conversion
    */
    if((num1<0) ^ (num2<0)){
        sign = 0;
        //negatve
    }
    else{
        sign =1;
        //postive
    }
    //making both postive
    int dividend = abs(num1);
    int divisor = abs(num2);

    int quotient = 0;
    while(dividend >= divisor){
        dividend = dividend - divisor ;
        quotient = quotient +1 ;
    }

    if(sign){
        return(quotient);
    }
    else{
        return(0-quotient);
    }

}
//using bit magic
int division_using_bits(long long num1,long long num2){
    bool sign;
    if((num1<0) ^ (num2<0)){
        sign = 0;
        //negatve
    }
    else{
        sign =1;
        //postive
    }
    //making both postive
    long long dividend = abs(num1);
    long long divisor = abs(num2);
    
    long long quotient = 0;
    long long temp =0;
    /*
    Example (10,3)
    we start checking from shifiting 31 bits ...
    here 10 = 1010
    3 = 0011
    here when we do 2 shifts
    1100->12
    so now we shift once 0110 -> 6
    Now temp + 6 <=10
    so temp = 6,quoitent = 1LL <<i | quoitent
    1LL == long long int num = 1
    that means we set ith bit for quoitent i = 1;
    set ith bit  quoitent = 2
    when i = 0;
    temp = 6+3 ;
    quoitent = 2|3
    quoitent = 3;
    so division is completed
    return quoitent
    Here why we are using long long?
    when we left shift by int by 31 which has 32 bits 
    we shift beyond the size of the integer type -> undefined behavior.
    With 1LL, you set the type 
    to long long before hand and now it will properly return value

    */
    for(int i = 31;i>=0;--i){
        if((temp + (divisor<<i) )<=dividend){
            temp = temp + (divisor<<i);
            quotient = quotient | (1LL << i);
        }
    }
 
    if(sign){
        return(quotient);
    }
    else{
        return(0-quotient);
    }


}
//O(log(num1)) we are delaing with bits here
//space O(1)
int main(){
    cout<<division_using_bits(43,-8)<<endl ;
    cout<<division(43,-8);
    return 0;
}