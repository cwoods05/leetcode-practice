class Solution {
    public:
    
        void  helper(vector<vector<char>>& grid, vector<vector<bool>>& seen, int i, int j){
            if(seen[i][j]) return;
            if(grid[i][j] == '0') return;
                
            seen[i][j] = true;
            
            if(i>0)
                helper(grid, seen, i-1, j);
            if(i < grid.size() - 1)
                helper(grid, seen, i+1, j);
            if(j>0)
                helper(grid, seen, i, j-1);
            if(j < grid[0].size() - 1)
                helper(grid, seen, i, j+1);
        }
    
        int numIslands(vector<vector<char>>& grid) {
            vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), false));
            int islands = 0;
    
            for(int i = 0; i < grid.size(); ++i){
                for(int j = 0; j < grid[0].size(); ++j){
                    if(!seen[i][j] && grid[i][j] == '1'){
                        ++islands;
                        helper(grid, seen, i, j);
                    }
                }
            }
    
            return islands;
        }
    };