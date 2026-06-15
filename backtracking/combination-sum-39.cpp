class Solution {
    public:
        void helper( const vector<int>& candidates, int index, int remaining,
            vector<int>& current, vector<vector<int>>& result){
                
            if (remaining == 0) {
                result.push_back(current);
                return;
            }
    
            if (remaining < 0 || index == candidates.size()) {
                return;
            }
    
            helper(candidates, index + 1, remaining, current, result);
    
            current.push_back(candidates[index]);
            helper(candidates, index, remaining - candidates[index], current, result);
            current.pop_back();
            return;
        
        }
        
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> result;
            vector<int> current;
        
            helper(candidates, 0, target, current, result);
        
            return result;
        }
    };