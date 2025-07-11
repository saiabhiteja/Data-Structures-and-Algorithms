class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        bool isr = false,isc= false ;
        int r = arr.size() ;
        int c = arr[0].size() ;
        for(int i = 0 ;i<r;i++){ 
            for(int j = 0;j<c;j++){
                if(arr[i][j] == 0){if(i == 0)isr =true ;
                if(j == 0)isc = true ;
                arr[i][0] = 0 ;
                arr[0][j] = 0 ;
            }
        }
    }
        for(int i = 1;i<r;i++){
            for(int j = 1;j<c;j++){
                if(arr[i][0] == 0 || arr[0][j] == 0){
                    arr[i][j] = 0 ;
                }
            }
        }
        
        if(isr){
            for(int i = 0 ;i<c;i++){
                arr[0][i] = 0 ;
            }
        }
        
        if(isc){
            for(int i = 0;i<r;i++){
                arr[i][0] = 0 ;
            }
        }
        
    }
};