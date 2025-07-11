#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    reversing queue
*/
void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
void method_1(queue<int>& q){
    vec temp ;
    while(!q.empty()){
        temp.push_back(q.front()) ;
        q.pop() ;
    }
    reverse(temp.begin(),temp.end()) ;
    for(int i: temp){
        q.push(i) ;
    }
    /*
    Time : O(N)
    SPace : O(N)
    */

}
void method_2(queue<int>& q){
    if(q.size() <= 1){
        return ;
    }
    int temp = q.front();
    q.pop() ;
    method_2(q);
    q.push(temp);
    /*
    Time : O(N)
    Space : O(N)
    */
}
int main() {

    queue<int> q ;
    q.push(1) ;
    q.push(2) ;
    q.push(3) ;
    display(q) ;
    method_2(q) ;
    display(q);

    return 0;
}