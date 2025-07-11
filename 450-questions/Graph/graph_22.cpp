#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
---Floyd warshall algorithm---
The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph
-1 reprsents no edge between two nodes
which implies distance between them is infinity
*/
void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0)) ;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                dp[i][j] = matrix[i][j] ;
            }
        }
	    for(int k = 0;k<n;k++){
	        for(int i = 0;i<n;i++){
	            for(int j = 0;j<n;j++){
	                if(dp[i][k]!=-1 && dp[k][j]!=-1){
	                    if(matrix[i][j] == -1){
	                        dp[i][j] = dp[i][k] + dp[k][j];
	                    }
	                    else{
	                        dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
	                    }
	                }
	                
	            }
	        }
	    }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<dp[i][j]<<" " ;
            }
            cout<<endl;
        }
        /*
        Time : O(N^3)
        Space : O(N*N)
        */
	}
int main() {
    vector<vector<int>> matrix = {{0,1,43},{1,0,6},{-1,-1,0}} ;
    shortest_distance(matrix);
    return 0;
}