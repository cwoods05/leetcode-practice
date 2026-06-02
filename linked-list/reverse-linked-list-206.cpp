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
        ListNode* reverseList(ListNode* head) {
            if(head == nullptr || head->next == nullptr) {
                return head; 
            }
            
            ListNode* prev = nullptr;
            ListNode* nextNode = nullptr;
            while(head != nullptr) {
                nextNode = head->next;  // 1. Save the next node
                head->next = prev;      // 2. Reverse the pointer direction
                prev = head;            // 3. Move 'prev' one step forward
                head = nextNode;        // 4. Move 'current' one step forward
            }
    
            return prev;
        }
    };