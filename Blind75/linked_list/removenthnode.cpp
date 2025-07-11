class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head ;
        ListNode* slow = head ;
        while(n>0){
            fast = fast->next ;
            n--;
        }
        if(!fast)return head->next ;
        while(fast->next){
            slow = slow->next ;
            fast = fast->next ;
        }
        slow->next = slow->next->next ;
        return head ;
    }
};