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
 struct CompareNode {
    bool operator()(ListNode* a, ListNode* b) {
        // Return true if "a" should have lower priority than "b"
        // For a min-heap, the element with the LARGER value goes to the bottom
        return a->val > b->val; 
    }
};

class Solution {
public:
    ListNode* merge(priority_queue<ListNode*, vector<ListNode*>, CompareNode>& minHeap,
        ListNode* answer, ListNode* tail) {
        while(minHeap.size() > 0){
            ListNode* first = minHeap.top();
            minHeap.pop();

            if(answer == nullptr){
                answer = first;
                tail = first;
            }
            else{
                tail->next = first;
                tail = tail->next; 
            }
            if(first->next != nullptr) minHeap.push(first->next);
            
            
        }
        return answer;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;
        ListNode* answer = nullptr;
        ListNode* tail = nullptr;

        for (ListNode* num : lists) {
            if(num != nullptr) minHeap.push(num);
        }

        answer = merge(minHeap, answer, tail);

        return answer;
    }
};