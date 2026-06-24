class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int furthest = 0; 
            
            for(int i = 0; i < nums.size(); ++i){
                if(i > furthest){
                    return false;
                }
                furthest = max(furthest, i + nums[i]);
                if(furthest >= nums.size()-1) return true;
    
    
            }
            return false;
        }
    };