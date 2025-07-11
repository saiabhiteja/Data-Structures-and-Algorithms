#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    find median two equal size sorted arrays
*/
int method_1(vector<int> arr1,vector<int> arr2){
    vector<int> temp ;
    int n = arr1.size();
    for(int i = 0;i<n;i++){
        temp.push_back(arr1[i]) ;
        temp.push_back(arr2[i]);
    }
    sort(temp.begin(),temp.end()) ;
    return ((temp[n]+temp[n-1])/2) ;
    /*
    Time : O(N) + O(2*NLog(2*N))
    Space :O(2*N)
    */
}

int method_2(vector<int> arr1,vector<int> arr2){
    vector<int> temp ;
    int curr = 0; //index value ;
    int n = arr1.size() ;
    int i = 0; //arr1 pointer
    int j = 0 ; //arr2 pointer
    //vector<int> temp ;
    while(i<n && j<n && curr<=n){
        if(arr1[i]<=arr2[j]){
            temp.push_back(arr1[i++]) ;
        }
        else{
            temp.push_back(arr2[j++]) ;
        }
        curr++;
        
    }

    for(int i: temp){
        cout<<i<<endl;
    }

    return ((temp[n]+temp[n-1])/2) ;
    /*
    Time : O(N)
    space : O(N)
    */
}

int method_3(vector<int> arr1,vector<int> arr2){
    int ele_n = 0; //element at index n
    int ele_n_1 = 0 ; //element at index n-1; 
    int i = 0,j = 0 ;
    int curr = 0;
    int n = arr1.size() ;
    while(i<n&&j<n&&curr<=n){
        if(arr1[i]<=arr2[j]){
            if(curr == n-1 || curr == n){
                if(curr == n-1){
                    ele_n_1 = arr1[i];
                }
                else{
                    ele_n = arr1[i] ;
                }
            }
            i++;
        }
        else{
            if(curr == n-1 || curr == n){
                if(curr == n-1){
                    ele_n_1 = arr2[j];
                }
                else{
                    ele_n = arr2[j] ;
                }
            }
            j++;
        }
        curr++;

    } 
    cout<<ele_n<<" "<<ele_n_1<<endl;
    return (ele_n+ele_n_1)/2 ;
    /*
    Time : O(N)
    Space : O(1)
    */
}

int method_4(vector<int> arr1,vector<int> arr2){
    //trying to fit first n-1 elements in arr1 and next in arr2
    int n = arr1.size() ;
    int j = 0;
    for(int i = n-1;i>=0;i--){
        if(j>=n){
            break ;
        }
        if(arr1[i]> arr2[j]){
            swap(arr1[i],arr2[j++]) ;
        }
        else{
            break ;
        }
    }
    sort(arr1.begin(),arr1.end()) ;
    sort(arr2.begin(),arr2.end()) ;
    return (arr1[n-1]+arr2[0])/2 ;
    /*
    Time : O(N)+O(Nlogn)
    Space : O(1)
    */
}

int get_median(int arr[],int n){
    if(n%2 == 0){
        return (arr[n/2]+arr[n/2 -1 ])/2 ;
    }
    return (arr[n/2]) ;
}

int method_5(int arr1[],int arr2[],int n){
    //using divide and conquer
    if(n<=0)
    return -1;
    if(n==1){
        return (arr1[0]+arr2[0])/2 ;
    }

    if(n==2){
        return (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2 ;
    }

    int m1 = get_median(arr1,n);
    int m2 = get_median(arr2,n) ;

    if(m1 == m2){
        return m1 ;
    }

    if(m1<m2){
        /*
         which one has greater value we have to find lesser value
        */
        if(n%2 == 0){
            return method_5(arr1+(n/2-1),arr2,n-(n/2-1));
        }
        return method_5(arr1+(n/2),arr2,n-(n/2)) ;
    }
    else{
        //m2>m1
        if(n%2 == 0){
            return method_5(arr1,arr2+(n/2 -1),n-(n/2-1)) ;
        }
        return method_5(arr1,arr2+(n/2),n-(n/2)) ;
    }

    /*
    Time : O(logn)
    SPace : O(1)
    */
    
}

int main() {
    int arr1[4]= {1, 2, 3, 6};
    int arr2[4] = {4, 6, 8, 10};

    cout<<method_5(arr1,arr2,4)<<endl;

    return 0;
}