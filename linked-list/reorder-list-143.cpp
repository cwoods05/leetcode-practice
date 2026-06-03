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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (list1 == nullptr) return list2;
            if (list2 == nullptr) return list1;
    
            ListNode* current = nullptr;
            current = list1;
            ListNode* temp = list1->next;
            current->next = list2;
            current->next->next = mergeTwoLists(temp, list2->next);
            return current;
        }
        
        void reorderList(ListNode* head) {
            // find midpoint
            ListNode* slow = head;
            ListNode* fast = head;
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
    
            // merge 1st half with reversed second half (starts with prev)
            mergeTwoLists(head, prev);
    
        }
    };