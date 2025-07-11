#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
#define nu NULL
/*
https://takeuforward.org/data-structure/delete-given-node-in-a-linked-list-o1-approach/
*/
void method1(node* pntr){

    node* nxt = pntr->next ;
    pntr->data = nxt->data ;

    pntr->next = nxt->next ;
    return ;
    /*
    Time : O(1)
    space : O(1)
    */

}
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
return 0;
}