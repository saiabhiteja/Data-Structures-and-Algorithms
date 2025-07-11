#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
/*
    implement min stack
    with time complexity : O(1)
*/
class mystack{
    private:
    stack<int> st ;
    int min_ele ;
    public:
    mystack(){
        min_ele = -1;
    }
    void push(int data){
        if(st.empty()){
            st.push(data) ;
            min_ele = data;
        }
        else{
            if(data<min_ele){
                int temp = data ;
                data = 2*data - min_ele ;
                min_ele = temp ;
            }
            st.push(data);
        }
    }

    void pop(){
        if(st.empty()){
            return ;
        }
        if(st.top()>min_ele){
            st.pop() ;
        }
        else{
            int temp = st.top();
            st.pop();
            min_ele = 2*min_ele - temp ;
        }

    }

    int get_min(){
        return min_ele ;
    }

};

int main() {

    mystack s1 ;
    s1.push(16) ;
    cout<<s1.get_min()<<endl;
    s1.push(19);
    cout<<s1.get_min()<<endl;
    s1.push(12);
    cout<<s1.get_min()<<endl;
    s1.push(14);
    cout<<s1.get_min()<<endl;
    s1.push(11);
    cout<<s1.get_min()<<endl;
    s1.pop();
    cout<<s1.get_min()<<endl;
    s1.pop();
    cout<<s1.get_min()<<endl;
    s1.pop();
    cout<<s1.get_min()<<endl;


return 0;
}