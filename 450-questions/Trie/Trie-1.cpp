#include "bits/stdc++.h"
using namespace std ;

//insert,search and starts with words ,finding prefix
/*
-------Trie-----
pointers [26] {0->a,1->b,2->c,3->d......25->z}
boolean islast 

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
int main(){
    trie t ;
    vector<string> s = {"saiabhiteja","saiabhinay","saija","sindhuja"};

    for(int i = 0;i<s.size();i++){
        t.insert(s[i]);
    }

    if(t.search("saiabhiteja")){
        cout<<"saiabhiteja is present"<<endl;
    }

    if(t.search("sai")){
        cout<<"Sai is present"<<endl;
    }
    else{
        cout<<"sai is not prsent"<<endl;
    }

    return 0;
}