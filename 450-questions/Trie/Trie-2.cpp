#include "bits/stdc++.h"
using namespace std;


struct node{
    node* links[26];
    int countprefix = 0;
    node(){
        for(int i =0 ;i<26;i++){
            links[i] = NULL ;
        }
    }
    bool iscontains(char c){
        return (links[c-'a']!=NULL);
    }
    void put(char ch,node* Node){
        links[ch-'a'] = Node;
    }
    node* get(char ch){
        return links[ch-'a'];
    }
    void increaseprefix(){
        countprefix++;
    }
    int getprefix(){
        return countprefix;
    }
};
class trie{
    private:
    node* root;
    public:
    trie(){
        root = new node();
    }
    void insert(string s){
        node* temp = root;
        for(int i = 0;i<s.length();i++){
            if(temp->get(s[i]) == NULL){
                temp->put(s[i],new node());
            }
            temp = temp->get(s[i]);
            temp->increaseprefix();
        }
        /*
        Time : O(len(s))
        */
    }
    
    string prefix(string s){
        node* temp = root;
        string ans = "";
        for(int i = 0;i<s.length();i++){
            ans = ans+s[i];
            temp = temp->get(s[i]);
            if(temp->getprefix() == 1){
                //checking for unique
                return ans;
            }
        }
        /*
        Time : O(len(s))
        */
       return " ";
    }
    
};

vector<string> findPrefixes(string arr[], int n){
        vector<string> ans;
       
       trie t;
       for(int i = 0;i<n;i++){
           t.insert(arr[i]);
       }
       for(int i = 0;i<n;i++){
           ans.push_back(t.prefix(arr[i]));
       }
       
       return ans;
       /*
       Time : O(N*len(s))
       */
       
}
int main(){
    string arr[] = {"zebra", "dog", "duck", "dove"} ;
    vector<string>ans =  findPrefixes(arr,4);
    for(auto it:ans ){
        cout<<it<<" ";
    }
    return 0;
}
    
