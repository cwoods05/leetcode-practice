/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode* dummy = new ListNode(0, head);
    
            ListNode* slow = dummy;
            ListNode* fast = dummy;
            int i = n;
            while(i != 0 && fast->next){
                fast = fast->next;
                i--;
            }
    
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next;
            }
    
            if(fast->next == nullptr){
                ListNode* temp = slow->next;
                slow->next = temp->next;
                delete temp;
            }
    
            return dummy->next;
        }
    };