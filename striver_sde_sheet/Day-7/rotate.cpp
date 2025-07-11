#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
https://takeuforward.org/data-structure/rotate-a-linked-list/
*/
node* rotate_list(node* head){
    node* prev = NULL ;
    for(auto temp = head;temp && temp->next ;temp = temp->next){
        prev = temp ;
    }
    prev->next->next = head;
    head = prev->next ;
    prev->next = NULL ;
    /*
    Time : O(N)
    space : O(1)
    */

}
node* method1(node* head,int k){
    for(int i = 0;i<k;i++){
        head = rotate_list(head) ;
    }
    return head ;
    /*
    Time : O(N*K)
    space : O(1)
    */
}

node* method2(node* head,int k){
    node* prev = NULL ;
    int len = 0 ;
    for(auto temp = head;temp;temp = temp->next){
        len++;
        prev = temp ;
    }
    prev->next = head ;
    k = k%len ;
    int req = len-k ; 
    while(req--){
        prev = prev->next ;
    }
    head = prev->next ;
    prev->next = NULL ;
    return head;
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