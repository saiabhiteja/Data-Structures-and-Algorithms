#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/
*/
node* method1(node* head){
    unordered_map<node*,bool> mp ;
    for(auto temp = head;temp;temp = temp->next){
        if(mp[temp]){
            return temp ;
        }
        mp[temp] = true ;
    }
    /*
    Time : O(N)
    space : O(N)
    */
}
node* method2(node* head){
    node* slow = head ;
    node* fast = head ;
    while(fast && fast->next){
        slow = slow->next ;
        fast = fast->next->next ;
    }
    fast = head ;
    while(fast!=slow){
        fast = fast->next ;
        slow = slow->next ;
    }
    return slow ;
    /*
    Time : O(N)
    space : O(1)
    */
}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}