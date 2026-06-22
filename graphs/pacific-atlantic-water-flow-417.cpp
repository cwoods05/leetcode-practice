class Solution {
    public:
        void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, 
            int r, int c, int prevHeight) {
    
            if(r < 0 || c < 0 || r > (heights.size() - 1) || c > (heights[0].size() - 1)) return;
            if(visited[r][c]) return;
            if(heights[r][c] < prevHeight) return;
    
            visited[r][c] = true;
    
            dfs(heights, visited, r-1, c, heights[r][c]);
            dfs(heights, visited, r+1, c, heights[r][c]);
            dfs(heights, visited, r, c-1, heights[r][c]);
            dfs(heights, visited, r, c+1, heights[r][c]);
    
            return;
        }
    
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            vector<vector<bool>> visitedP(heights.size(), vector<bool>(heights[0].size(), false));
            vector<vector<bool>> visitedA(heights.size(), vector<bool>(heights[0].size(), false));
            vector<vector<int>> answer;
    
            for(int i = 0; i < heights[0].size(); ++i){
                dfs(heights, visitedP, 0, i, 0);
                dfs(heights, visitedA, heights.size()-1, i, 0);
            }
    
            for(int i = 0; i < heights.size(); ++i){
                dfs(heights, visitedP, i, 0, 0);
                dfs(heights, visitedA, i, heights[0].size()-1, 0);
            }
    
            for(int r = 0; r < heights.size(); ++r){
                for(int c = 0; c < heights[0].size(); ++c){
                    if(visitedP[r][c] && visitedA[r][c]){
                        answer.push_back({r, c});
                    }
                }
            }
    
            return answer;
        }
    };