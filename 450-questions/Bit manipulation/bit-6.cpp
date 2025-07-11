#include <iostream>
#include "bits/stdc++.h"
using namespace std;
int findPosition(int N) {
        int count = 0;
        int pos = 0;
        while(N!=0){
            if(N&1 == 1){
                count = count+1;
            }
            N = N>>1;
            pos = pos+1;
            
        }
        if(count==0 || count>1){
            return -1;
        }
        else{
            return pos;
        }
    }
int main(){
    cout<<findPosition(16)<<endl;
    return 0;
}