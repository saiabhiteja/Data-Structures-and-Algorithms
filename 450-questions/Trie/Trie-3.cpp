#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mod 1e9+7
/*
--- word break problem ---
*/
struct node{
    node* links[26];
    bool flag = false ; 

    node(){
        //intalising the values
        for(int i = 0;i<26;i++){
            links[i] = nullptr ;
        }
        flag = false ;
    }

    bool iscontains(char ch){
        //checking wether the charcter is already there are not
        return (links[ch-'a'] != NULL) ;

    }

    void put(char ch,node* Node){
        //for inserting new node to particular node
        links[ch-'a'] = Node ;
    }

    node* get(char ch){
        //for getting particular link 
        return links[ch-'a'];
    }

    void setend(){
        //for setting flag
        flag = true;
    }

    bool getflag(){
        //for getting flag
        return flag;
    }

};

class trie{
    private:
    node* root ;

    public:

    trie(){
        root = new node();
    }

    //inserting every words in to trie
    void insert(string s){
        node* temp = root ;
        for(int i = 0;i<s.size();i++){
            if(!temp->iscontains(s[i])){
                temp->put(s[i],new node()) ;
            }
            //moves to the new refernce trie...
            temp = temp->get(s[i]) ;
        }
        temp->setend();

        /*
        -----------complexities-------
        time : O(len(s))
        */
    }

    //searching a word in trie

    bool search(string s){
        node* temp = root ;
        for(int i = 0;i<s.size();i++){
            if(!temp->get(s[i])){
                return false ;
            }
            //if not null go to that char link ;
            temp = temp->get(s[i]);
        }
        return temp->getflag();

        /*
        -----------complexities-------
        time : O(len(s))
        */
    }


};


    
    bool helper(trie t,string s){
        if(s.size()== 0){
            return true;
        }
        for(int i = 1;i<=s.length();i++){
            if(t.search(s.substr(0,i)) && helper(t,s.substr(i,s.size()-i))){
                return true;
            }
        }
        return false;
    }
   
    int wordBreak(string A, vector<string> &B) {
       trie t ;
       for(string s: B){
           t.insert(s);
       }
      
       return helper(t,A) ;
     
    }

int main() {
    vector<string> B = { "i", "like", "sam", "sung", "samsung","mobile","ice","cream", "icecream", "man", "go", "mango" };
    string  A = "ilikesamsung" ;

    cout<<wordBreak(A,B)<<endl;



    return 0;
}