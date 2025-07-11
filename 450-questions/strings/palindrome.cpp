#include <iostream>
using namespace std;
	int isPlaindrome(string S)
	{
	    // Your code goes here
	    int len = S.length();
	    int flag = 0;
	    for(int i = 0;i<S.length()/2;i++)
	    {
	        if(S[i]!=S[len-i-1]){
	            flag = 1;
	            break ;
	            
	        }
	    }
	    if (flag==0)
	    {
	        return 1;
	    }
	    else{
	        return 0;
	    }
	}
int main(){
    string text = "saiabhiteja";
    int x = isPlaindrome(text);
    if(x==1){
        cout<<"Text is palindrome"<<endl ;

    }
    else{
        cout<<"Text is not palindrome"<<endl ;
    }
    return 0 ;

}