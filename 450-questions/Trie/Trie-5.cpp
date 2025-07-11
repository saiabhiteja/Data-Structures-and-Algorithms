#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mod 1e9+7
/*
*/
/*struct node{
    node* links[26];
    int countprefix = 0;
    vector<int> prefix_index ;
    
    node(){
        for(int i = 0;i<26;i++){
            links[i] = nullptr;
        }
    }

    bool iscontains(char ch){
        //checking wether the charcter is already there are not
        return (links[ch-'a'] != NULL) ;

    }

    void put(char ch,node* Node){
        links[ch-'a'] = Node ;
    }

    node* get(char ch){
        //for getting particular link 
        return links[ch-'a'];
    }
    
   
    void increaseprefix(){
        countprefix++;
    }
   
    void decreaseprefix(){
        countprefix-- ;
    }
    int getprefix(){
        return countprefix;
    }
};

class trie{
    private:
    node* root ;
    public:
    trie(){
        root = new node();
    }

    void insert(string s,int ind){
        node* temp = root ;
        for(int i = 0;i<s.size();i++){
            if(!temp->iscontains(s[i])){
                temp->put(s[i],new node());
            }
            
            temp = temp->get(s[i]);
            temp->increaseprefix();
            temp->prefix_index.push_back(ind);
        }
    }
    
    vector<string> get_strings(string s,string con[]){
        node* temp = root;
        vector<string> ans ;
        set<string> se;
        for(int i = 0;i<s.length();i++){
            if(!temp->get(s[i])){
                return {"0"};
            }
            temp = temp->get(s[i]);
        }
        vector<int> indexes = temp->prefix_index ;
        for(int i = 0;i<indexes.size();i++){
            se.insert(con[indexes[i]]);
        }
        for(auto it:se){
            ans.push_back(it);
        }
        return ans;
        
    }

    

   
   

};

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        trie t;
        sort(contact,contact+n);
        for(int i = 0;i<n;i++){
            t.insert(contact[i],i);
        }
        vector<vector<string>> ans;
        string temp;
        for(int i = 0;i<s.length();i++){
            temp = temp + s[i];
            vector<string> t1 = t.get_strings(temp,contact);
            ans.push_back(t1);
        }
        return ans;
    }
*/
//2nd approach using recusion
struct node{
    
    node* links[26];
    bool isend ;
    
    node(){
        for(int i = 0;i<26;i++){
            links[i] = nullptr;
        }
        isend = false ;
    }

    bool iscontains(char ch){
        //checking wether the charcter is already there are not
        return (links[ch-'a'] != NULL) ;

    }

    void put(char ch,node* Node){
        links[ch-'a'] = Node ;
    }

    node* get(char ch){
        //for getting particular link 
        return links[ch-'a'];
    }
    void set_end(){
        isend = true ;
    }
    bool get_end(){
        return isend ;
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
        for(int i = 0;i<s.size();i++){
            if(!temp->iscontains(s[i])){
                temp->put(s[i],new node());
            }
            
            temp = temp->get(s[i]);
            
           
        }
         temp->set_end();
         /*
         Time : O(len(s))
         */
    }
    
    vector<string> get_strings(string s){
        
        node* temp = root;
        vector<string> ans ;
        
        
        for(int i = 0;i<s.length();i++){
            if(!temp->get(s[i])){
                return {"0"};
            }
            temp = temp->get(s[i]);
        }
        
        helper(temp,ans,s);
        return ans;
        
    }
    
    void helper(node* temp,vector<string>& ans,string t){
        if(!temp) return ;
        if(temp->get_end()){
            ans.push_back(t);
        }
        for(int i = 0;i<26;i++){
            char ch = i+'a' ;
            if(temp->get(ch)){
                t = t + ch ;
                helper(temp->get(ch),ans,t);
                t.pop_back();
            }
        }
        return ;
        /*
        Time : O(26^k) k = max(len(s))
        */
    }
};

vector<vector<string>> displayContacts(int n, string con[], string s)
    {
        trie t;
        for(int i = 0;i<n;i++){
            t.insert(con[i]);
        }
        
        vector<vector<string>> ans ;
        
        string temp = "";
        for(int i = 0;i<s.length();i++){
            temp.push_back(s[i]);
            ans.push_back(t.get_strings(temp)) ;
        }
        
        return ans ;
        /*
        Time : O(N*len(str)) + O(len(s)*26^k)
        */
        
    }

int main() {
    string con[3] ={"geeikistest", "geeksforgeeks", 
"geeksfortest"} ;
    vector<vector<string>> ans = displayContacts(3,con,"geeips");
    for(auto it : ans){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<"$"<<endl;
    }

return 0;
}