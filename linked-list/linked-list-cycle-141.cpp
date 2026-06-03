/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
    public:
        bool hasCycle(ListNode *head) {
            std::unordered_set<ListNode*> visitedNodes;
    
            ListNode* current = head;
            while(current != nullptr){
                if(visitedNodes.find(current) != visitedNodes.end()){
                    return true;
                }
    
                visitedNodes.insert(current);
                current = current->next;
            }
    
            return false;
        }
    };

    //Use two pointers like this to get 3 ms runtime: 

    /*
    
    class Solution {
    public:
        bool hasCycle(ListNode *head) {
            ListNode* slow = head;
            ListNode* fast = head;

            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;

                if (slow == fast) {
                    return true;
                }
            }

            return false;
        }
    };

    */