#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    m colouring 
*/
bool issafe(int graph[101][101],int r,int k,vector<int>& color){
    for(int j = 0;j<101;j++){
        if(graph[r][j] == 1){
            if(color[j] == k){
                return false;
            }
        }
    }

    return true;
}
bool helper(int graph[101][101],int m,int i,vector<int>& color){
    if(i>= color.size()){
        return true;
    }
    for(int k = 0;k<m;k++){
        if(issafe(graph,i,k,color)){
            color[i] = k ;
            if(helper(graph,m,i+1,color)){
                return true;
            }
            color[i] = -1;
        }
    }
    return false;
}
bool can_be_colured(int graph[101][101],int m,int v){
    vector<int> color(v,-1) ;
    return helper(graph,m,0,color);
    /*
    Time : O(M^V)
    SPace : O(V)
    */
}
int main() {

    return 0;
}