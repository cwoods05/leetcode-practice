class Solution {
    public:
        int lastStoneWeight(vector<int>& stones) {
            priority_queue<int> maxHeap;
        
            for (int num : stones) {
                maxHeap.push(num);
            }
    
            while(maxHeap.size() > 1){
                int stone1 = maxHeap.top();
                maxHeap.pop();
                int stone2 = maxHeap.top();
                maxHeap.pop();
    
                if(stone1 == stone2) continue;
                if(stone1 != stone2){
                    stone1 = stone1 - stone2;
                    maxHeap.push(stone1);
                }
            }
            if(maxHeap.size() > 0) return maxHeap.top();
            return 0;
        }
    };