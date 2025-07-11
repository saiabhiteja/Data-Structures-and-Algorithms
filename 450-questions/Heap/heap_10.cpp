#include <bits/stdc++.h>
using namespace std;
#define vec vector<int>
#define pp pair<int,int>
#define ll long long
#define mat vector<vector<int>>
/*
    Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.
*/
struct Node{
    int data ;
    Node* next ;
    Node(int x){
        data = x ;
        next = NULL ;
    }
};
struct Comparevalue {
    bool operator()(Node* p1,Node* p2)
    {
        return p1->data > p2->data;
    }
};
class Solution{
     public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
        Node* ans = new Node(-1) ;
        Node* head = ans ;
        priority_queue<Node*,vector<Node*>,Comparevalue> pq ;
         for(int i = 0;i<k;i++){
            pq.push(arr[i]) ;
         }
         while(pq.size()!=0){
             Node* to = pq.top() ;
             pq.pop() ;
             if(to->next){
                 pq.push(to->next);
             }
             head->next = to ;
             head = head->next ;
         }
         
        
         return ans->next;
         /*
         Time : O(N*klogk)
         space : O(k)
         */
    }
};
int main() {
return 0;
}