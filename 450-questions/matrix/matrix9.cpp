#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    kth smallest number in column and row wise sorted matrix
*/
int method_1(vector<vector<int>>& mat,int n,int k){
    //finding kth smallest number
    vector<int> temp ;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            temp.push_back(mat[i][j]);
        }
    }
    sort(temp.begin(),temp.end()) ;
    return temp[k-1];
    /*
    Time : O(N*N + O((N*N)log(N*N)))
    Space : O(N*N)
    */
}

int helper(vector<vector<int>>& mat,int row,int key,int n){
    //this function send number if elements less than or equal to current mid value
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = (low) +(high-low)/2 ;
        if(mat[row][mid]<=key){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low ;
}
int method_2(vector<vector<int>>&mat,int n,int k){
    //using binary search
    int low = mat[0][0] ; //since matrix is row and column wise sorted matrix
    int high = mat[n-1][n-1] ;
    //our search space is low - high
    while(low<=high){
        int mid = low + (high-low)/2 ;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            cnt+=helper(mat,i,mid,n);
        }
        if(cnt<=(k-1)){
            low = mid+1; //when the value equal to k-1 we go to low = mid+1 because 
            //including mid element we have k-1 elements which are less than equal to it we need kth element so we go to mid+1
        }
        else{
            high = mid-1;
        }
    }
    return low ;
    /*
    Time : O(log2(max-min)*n*log2(n))
    SPace : O(1)
    */
}




//using priority_queue
int method_3(vector<vector<int>>& mat,int n,int k){
    //using lambda function
    auto cmp = [&](pair<int,int> a,pair<int,int> b){
        return mat[a.first][a.second] > mat[b.first][b.second];
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);

    //push all first column elements
    for(int i = 0;i<n;i++){
        pq.push({i,0}) ;
    }

    for(int i = 1;i<k;i++){
        auto p = pq.top();
        pq.pop();
        if(p.second+1<n){
            pq.push({p.first,p.second+1});
        }
    }
    return mat[pq.top().first][pq.top().second];
    /*
    Time : O(nlogn) + O(klogn)
    Space : O(n)
    */
}


int main() {
/**/
return 0;
}