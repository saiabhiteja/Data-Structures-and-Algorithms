#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    the celebirty problem
*/
int celebrity(vector<vector<int> >& arr, int n) 
    {
        vector<int>adj[n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(arr[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>indegree(n,0),outdegree(n,0);
        for(int i = 0;i<n;i++){
            for(auto it: adj[i]){
                indegree[it]++;
                outdegree[i]++;
            }
        }
        
        for(int i = 0;i<n;i++){
            if(outdegree[i] == 0 && indegree[i] == n-1){
                return i;
            }
        }
        
        return -1;
        /*
        using graph concept
        Time : O(V+E) + O(N^2)
        Space : O(V+E)
        */
        
}
int method_2(mat& arr,int n){
    //using stack
    stack<int> st ;
    for(int i = 0;i<n;i++){
        //pushing all members into stack
        st.push(i) ;
    }
    while(st.size()>1){
        int first = st.top();
        st.pop();
        int second = st.top();
        st.pop();
        if(arr[first][second]){
            st.push(second);
        }
        else{
            st.push(first);
        }
    }
    if(st.size() == 1){
        int c = st.top() ;
        for(int i = 0;i<n;i++){
            if(i!=c &&(arr[c][i] || !(arr[i][c])))return -1;
        }
        return c ;
    }
    return -1;
    /*
    Time : O(N)
    Space : O(N)
    */
}
int main() {
    mat arr = {{0 ,1, 0},
         {0 ,0 ,0}, 
         {0 ,1, 0}} ;
    cout<<celebrity(arr,3);
    return 0;
}