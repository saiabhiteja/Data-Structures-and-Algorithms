int maxones(vector<int> arr){
    int ans = 0 ;
    int n = arr.size() ;
    int tmp = 0 ;
    for(int i = 0;i<n;i++){
        if(arr[i]){
            tmp++;
        }
        else{
            tmp = 0 ;
        }
        ans = max(ans,tmp) ;
    }
    return ans ;
    /*
    Time : O(N)
    space : O(1)
    */
}