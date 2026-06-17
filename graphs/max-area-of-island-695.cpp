class Solution {
    public:
        void helper(vector<vector<int>>& grid, vector<vector<bool>>& seen, 
            int& islandArea, int i, int j){
    
            if(seen[i][j]) return;
            if(grid[i][j] == 0) return;
                
            seen[i][j] = true;
            ++islandArea;
            
            if(i>0)
                helper(grid, seen, islandArea, i-1, j);
            if(i < grid.size() - 1)
                helper(grid, seen, islandArea, i+1, j);
            if(j>0)
                helper(grid, seen, islandArea, i, j-1);
            if(j < grid[0].size() - 1)
                helper(grid, seen, islandArea, i, j+1);
    
            
        }
        
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
            int islands = 0;
            int maxIslandArea = 0;
    
            for(int i = 0; i < grid.size(); ++i){
                for(int j = 0; j < grid[0].size(); ++j){
                    if(!seen[i][j] && grid[i][j] == 1){
                        ++islands;
                        int islandArea = 0;
                        helper(grid, seen, islandArea, i, j);
    
                        if(islandArea > maxIslandArea){
                            maxIslandArea = islandArea;
                        }
                    }
                }
            }
    
            return maxIslandArea;
        }
    };