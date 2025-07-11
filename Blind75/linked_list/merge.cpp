class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)return list2 ;
        if(!list2)return list1 ;
        if(list1->val>list2->val)swap(list1,list2) ;
        ListNode* ans = list1 ;
        while(list1 && list2){
            ListNode* prev = NULL ;
            while(list1 && list1->val<=list2->val){
                prev = list1 ;
                list1 = list1->next ;
            }
            if(prev)prev->next = list2 ;
            swap(list1,list2) ;
        }
        return ans ;
    }
};