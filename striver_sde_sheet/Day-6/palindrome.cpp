#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
https://takeuforward.org/data-structure/check-if-given-linked-list-is-plaindrome/
*/
node* middle_element(node* head){
    node* slow = head ;
    node* fast = head ;
    while(fast && fast->next){
        slow = slow->next ;
        fast = fast->next->next ;
    }
    return slow ;
    /*
    Time : O(N/2)
    space : O(1)
    */
}
node* reverse(node* head){
    node* prev = NULL ;
    node* curr = head ;
    node* nxt = head ;
    while(curr){
        nxt = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = nxt ;
    }
    return prev ;
    /*
    Time : O(N)
    space : O(1)
    */
}
bool method1(node* head){
    //node* mid = middle_element(head) ;
    node* slow = head ;
    node* fast = head ;
    node* prev = NULL ;
    while(fast && fast->next){
        prev = slow ;
        slow = slow->next ;
        fast = fast->next->next ;
    }
    prev->next = reverse(slow) ;
    while(head && slow){
        if(head->data != slow->data){
            return false ;
        }
        head = head->next ;
        slow = slow->next ;
    }

    return true ;
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