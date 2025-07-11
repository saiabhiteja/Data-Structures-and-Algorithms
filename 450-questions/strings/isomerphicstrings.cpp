#include <iostream>
using namespace std;

bool areIsomorphic(string str1, string str2){
        if(str1.length()!=str2.length())
        {
            return false ;
        }
        int c1[256] = { 0 };
        int c2[256] = { 0 };
        for (int i = 0; i < str1.length(); i++) {
        c1[str1[i]]++;
        c2[str2[i]]++;
        if (c1[str1[i]] != c2[str2[i]])
            return false;
    }
        
        return true;
        
}

int main(){
    bool b1 = areIsomorphic("aab","xxy");
    if(b1){
        cout<<"Isomerphic";
    }
    else
    {
        cout<<"Not isomerphic";
    }
    return 0;
}