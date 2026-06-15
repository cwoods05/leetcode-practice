class Solution {
    public:
    
        void helper( const vector<int>& nums, int index,
            vector<int>& current, vector<vector<int>>& result){
                
            if (index == nums.size()){
                vector<int> cur = current;
                result.push_back(cur);
                return;
            }
            helper(nums, index + 1, current, result);
    
            current.push_back(nums[index]);
            helper(nums, index + 1, current, result);
            current.pop_back();
            return;
       
        }
    
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> current;
    
            helper(nums, 0, current, result);
    
            return result;
        }
    };