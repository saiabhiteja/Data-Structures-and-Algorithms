#include <iostream>
#include "bits/stdc++.h"
using namespace std;
struct Item{
    int value;
    int weight;
};
bool compare(Item i1,Item i2){
    double p1 = double(i1.value)/i1.weight ;
    double p2 = double(i2.value)/i2.weight ;
    return p1>p2 ;
    
}
double fractionalKnapsack(int W, Item arr[], int n)
    {
        double profit = 0;
        sort(arr,arr+n,compare);
        int w = 0;
        for(int i = 0;i<n;i++){
            if((w+arr[i].weight)<=W ){
                profit = profit + arr[i].value ;
                w = w+arr[i].weight;
            }
            else{
                int remain = W-w;
                double temp = ((remain)*(double(arr[i].value)))/arr[i].weight ;
                profit = profit + temp;
                break;
            }
        }
        return profit;
    }
int main(){
    Item arr[] = {{60,10},{100,20}};
    cout<<fractionalKnapsack(50,arr,2);
    return 0;
}