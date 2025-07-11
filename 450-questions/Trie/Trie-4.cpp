#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mod 1e9+7
/*
print all anagrams together
*/
struct node{
    node* links[26] ;
    vector<int> indexes ;
    bool isend ;
    node(){
        for(int i = 0;i<26;i++){
            links[i] = NULL;
        }
        isend = true;
    }
    
    bool contains(char ch){
        return links[ch-'a'] ;
    }
    
    void put(char ch,node* Node){
        links[ch-'a'] = Node;
    }
    
    node* get(char ch){
        return links[ch-'a'];
    }
    
    void set_end(){
        isend = true;
    }
    
    bool get_end(){
        return isend ;
    }
    void push_ind(int ind){
        indexes.push_back(ind);
    }
    vector<int> get_indexes(){
        return indexes ;
    }
};
class trie{
    private: 
    node* root = NULL ;
    public : 
    trie(){
        root = new node();
    }
    
    void insert(string s ,int ind){
        node* temp = root;
        for(int i = 0;i<s.length();i++){
            if(!temp->contains(s[i])){
                temp->put(s[i],new node());
            }
            temp = temp->get(s[i]);
        }
        temp->push_ind(ind);
        temp->set_end();
        /*
        Time : O(len(s))
        */
    }
    
    vector<vector<int>> get_index(){
        node* temp = root;
        vector<vector<int>> ans ;
        helper(temp,ans);
        return ans;
        /*
        Time : O(26^max(len(s)))))
        */
    }
    
    void helper(node* temp,vector<vector<int>>& ans){
        if(!temp) return ;
        if(temp->get_end()){
            ans.push_back(temp->get_indexes());
        }
        for(int i = 0;i<26;i++){
            char ch = i+'a' ;
            if(temp->get(ch)){
                helper(temp->get(ch),ans);
            }
        }
        return;
    }
  
};

vector<vector<string> > Anagrams(vector<string>& str_list) {
        trie t ;
        int n = str_list.size();
        for(int i = 0;i<n;i++){
            string buffer = str_list[i] ;
            sort(buffer.begin(),buffer.end());
            t.insert(buffer,i);
        }
        
        vector<vector<int>> index = t.get_index();
        vector<vector<string>> ans ;
        for(auto it : index){
            vector<string> temp ;
            if(it.size()!=0){
                for(auto i : it){
                temp.push_back(str_list[i]);
            }
            ans.push_back(temp) ;
            }
        }
        return ans ;
        /*
        Time : O(N*len(s)*log(len(s))) + O(26^max(len(s))) 
        space : O(N*N)
        */
    }

int main() {
    vector<string> str_list = {"act","god","cat","dog","tac"} ;
    vector<vector<string>> ans = Anagrams(str_list) ;
    for(auto it: ans){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
return 0;
}