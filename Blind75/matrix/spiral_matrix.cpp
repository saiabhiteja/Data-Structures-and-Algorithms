class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>&arr) {
        vector<int> ans ;
        int r = arr.size() ;
        int c = arr[0].size() ;
        int left = 0 ;
        int right = c-1 ;
        int top = 0 ;
        int bottom = r-1 ;
        int dir = 0 ;
        while(top<=bottom && left<=right ){
            if(dir == 0 ){
                for(int i = left;i<=right;i++){
                    ans.push_back(arr[top][i]) ;
                }
                top++ ;
            }
            else if(dir == 1){
                for(int i = top;i<=bottom;i++){
                    ans.push_back(arr[i][right]) ;
                }
                right--;
            }
            else if(dir == 2){
                for(int i = right;i>=left;i--){
                    ans.push_back(arr[bottom][i]) ;
                }
                bottom--;
            }
            else{
                for(int i= bottom;i>=top;i--){
                    ans.push_back(arr[i][left]) ;
                }
                left++;
            }
            dir = (dir+1)%4 ;
        }
        return ans;
    }
};