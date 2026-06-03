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
        bool isPalindrome(ListNode* head) {
            // find midpoint
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* slow = dummy;
            ListNode* fast = dummy;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* second = slow->next;
            slow->next = nullptr;
            
            //reverse second half
            ListNode* prev = nullptr;
            ListNode* nextNode = nullptr;
            while(second != nullptr) {
                nextNode = second->next;  // 1. Save the next node
                second->next = prev;      // 2. Reverse the pointer direction
                prev = second;            // 3. Move 'prev' one step forward
                second = nextNode;        // 4. Move 'current' one step forward
            }
    
            while(head && prev){
                if(head->val != prev->val){
                    return false;
                }
    
                head = head->next;
                prev = prev->next;
            }
            return true;
        }
    };