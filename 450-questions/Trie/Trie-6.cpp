#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mod 1e9+7
/*
Finding unique rows in a binary matrix
*/
struct node{
    node* links[2] ;
    node(){
        links[1] = NULL ;
        links[0] = NULL ;
    }
    
    bool contains(char ch){
        return !(links[ch-'0'] == NULL);
    }
    
    node* next(char ch){
        return links[ch-'0'];
    }
    
    void put(char ch,node* Node){
        links[ch-'0'] = Node;
    }
    
};
class trie{
    private:
    node* root ;
    public:
    trie(){
        root = new node();
    }
    
    void insert(string s){
        node* temp = root ;
        for(int i = 0;i<s.length();i++){
            if(!temp->contains(s[i])){
                temp->put(s[i],new node());
            }
            temp = temp->next(s[i]);
        }
        /*
         Time : O(Len(s))
        */
    }
    
    bool search(string s){
        node* temp = root;
        for(int i = 0;i<s.length();i++){
            if(!temp->contains(s[i])){
                return false;
            }
            temp = temp->next(s[i]);
        }
        return true;
        /*
        Time : O(len(s))
        */
    }
};
/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[4][4],int row,int col){
    vector<vector<int>> ans ;
    string temp ="";
    vector<int> temp_vec ;
    for(int i = 0;i<col;i++){
        temp_vec.push_back(M[0][i]);
        temp.push_back(M[0][i]+'0');
    }
    trie t ;
    t.insert(temp);
    ans.push_back(temp_vec);
    for(int i = 1;i<row;i++){
        temp_vec.clear() ;
        temp.clear();
        for(int j = 0;j<col;j++ ){
            temp_vec.push_back(M[i][j]);
            temp.push_back(M[i][j]+'0');
        }
        if(!t.search(temp)){
            ans.push_back(temp_vec);
            t.insert(temp);
        }
        
    }
    return ans;
    /*
    Time : O(N*M)
    Space : O(N*M)
    */
    }
int main() {

    int arr[4][4] = {{1,0,0,1},
                    {0,0,0,0},
                    {1,1,1,1},
                    {1,0,0,1}} ;

    vector<vector<int>> ans = uniqueRow(arr,4,4);

    for(auto it : ans){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<"$"<<" ";
    }

    return 0;
}