/*
// quick select soln

class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        int pivot = nums[right];
        int storeIndex = left;

        for(int i = left; i < right; ++i){
            if(nums[i] < pivot){
                int temp = nums[i];
                nums[i] = nums[storeIndex];
                nums[storeIndex] = temp;
                ++storeIndex;
            }
        }

        int temp = nums[right];
        nums[right] = nums[storeIndex];
        nums[storeIndex] = temp;

        return storeIndex;
    }
    
    int quickSelect(vector<int>& nums, int left, int right, int target){
        int pivotIndex = 0;

        while(left <= right){
            pivotIndex = partition(nums, left, right);

            if(pivotIndex == target){
                return nums[pivotIndex];
            }
            else if(pivotIndex < target){
                left = pivotIndex + 1;
            }
            else{
                right = pivotIndex - 1;
            }
        }

        return nums[pivotIndex];
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int left = 0;
        int right = nums.size()-1;
        return quickSelect(nums, left, right, target);
    }
};

*/

class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int, vector<int>, greater<int>> minHeap;
    
            for (int num : nums) {
                minHeap.push(num);
    
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
    
            return minHeap.top();
        }
    };