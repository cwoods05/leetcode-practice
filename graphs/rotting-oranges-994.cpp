class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int totalMins = 0;
            int numFresh = 0;
            queue<pair<int,int>> q;
    
            for(int r = 0; r < grid.size(); ++r){
                for(int c = 0; c < grid[0].size(); ++c){
                    if(grid[r][c] == 2){
                        q.push({r,c});
                    }
                    if(grid[r][c] == 1){
                        ++numFresh;
                    }
                }
            }
    
            while(!q.empty()){
                int size = q.size();
                bool rottedThisMin = false;
    
                for(int i = 0; i < size; ++i){
                    auto [r, c] = q.front();
                    q.pop();
    
                    if(r > 0 && grid[r-1][c] == 1){
                        grid[r-1][c] = 2;
                        q.push({r-1, c});
                        rottedThisMin = true;
                        --numFresh;
                    }
                    if(r < grid.size()-1 && grid[r+1][c] == 1){
                        grid[r+1][c] = 2;
                        q.push({r+1, c});
                        rottedThisMin = true;
                        --numFresh;
                    }
                    if(c > 0 && grid[r][c-1] == 1){
                        grid[r][c-1] = 2;
                        q.push({r, c-1});
                        rottedThisMin = true;
                        --numFresh;
                    }
                    if(c < grid[0].size()-1 && grid[r][c+1] == 1){
                        grid[r][c+1] = 2;
                        q.push({r, c+1});
                        rottedThisMin = true;
                        --numFresh;
                    }
                }
    
                if(rottedThisMin) ++totalMins;
            }
        
            if(numFresh > 0){
                return -1;
            } 
            else{
                return totalMins;
            } 
        }
    };