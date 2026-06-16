class Solution {
    public:
        void helper( const vector<int>& nums, vector<bool>& used, 
            vector<int>& current, vector<vector<int>>& result){
                
            if (current.size() == nums.size()){
                vector<int> curr = current;
                result.push_back(curr);
                return;
            }
    
            for(int i = 0; i < nums.size(); ++i){
                if (used[i]){
                    continue;
                }
                current.push_back(nums[i]);
                used[i] = true;
                helper(nums, used, current, result);
    
                current.pop_back();
                used[i] = false;
            }
        
        }
    
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> result;
            vector<int> current;
            vector<bool> used(nums.size(), false);
    
            helper(nums, used, current, result);
    
            return result;
        }
    };