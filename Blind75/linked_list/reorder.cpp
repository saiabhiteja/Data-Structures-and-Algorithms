class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head ;
        ListNode* prev = NULL ,*nxt = NULL ;
        while(curr){
            nxt = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = nxt ;
        }
        return prev ;
    }
    ListNode* middle(ListNode* head){
        ListNode* slow = head ;
        ListNode* fast = head ;
        while(fast && fast->next){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        return slow ;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* curr = middle(head) ;
        ListNode* second = curr->next ;
        curr->next = NULL ;
        second = reverse(second) ;
        ListNode* temp = head ;
        while(second){
            ListNode* nxt = second->next ;
            second->next = temp->next ;
            temp->next = second ;
            temp = second->next ;
            second = nxt ;
        }
            
    }
};