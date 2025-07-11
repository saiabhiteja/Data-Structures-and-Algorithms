#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9
#define vec vector<int>
#define pp pair<int,int>
/*

    solving a suduko


*/
bool isvalid(int Mat[9][9],int row,int col,int val){
    for(int i = 0;i<9;i++){
        if(Mat[row][i] == val) return false;
        if(Mat[i][col] == val) return false;
        int sqr_x = 3*(row/3)+i/3 ;
        int sqr_y = 3*(col/3) +i%3;
        if(Mat[sqr_x][sqr_y] == val) return false ;
    }
    return true;

}
bool solve_suduko(int Mat[9][9]){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(Mat[i][j] == 0){
                //which says it is empty
                //so if have 9 choices to fill it
                for(int k = 1;k<=9;k++){
                    if(isvalid(Mat,i,j,k)){
                        Mat[i][j] = k ;
                        if(solve_suduko(Mat)){
                            return true;
                        }
                        else{
                            Mat[i][j] = 0;
                        }

                    }

                }
                return false;
            }
        }
    }
    return true;
    /*
    Time : O(9^N*N)
    Space : O(N*N) //stack
    */
}
int main() {

    int Mat[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
{5, 2, 0, 0, 0, 0, 0, 0, 0},
{0, 8, 7, 0, 0, 0, 0, 3, 1 },
{0, 0, 3, 0, 1, 0, 0, 8, 0},
{9, 0, 0, 8, 6, 3, 0, 0, 5},
{0, 5, 0, 0, 9, 0, 6, 0, 0},
{1, 3, 0, 0, 0, 0, 2, 5, 0},
{0, 0, 0, 0, 0, 0, 0, 7, 4},
{0, 0, 5, 2, 0, 6, 3, 0, 0}} ;

    solve_suduko(Mat);
    for(int i=0;i<9;i++){
        for(int j = 0;j<9;j++){
            cout<<Mat[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

