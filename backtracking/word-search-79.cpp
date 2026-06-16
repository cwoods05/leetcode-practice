class Solution {
    public:
        
        bool dfs(vector<vector<char>>& board, int r, int c, int i,
            vector<vector<bool>>& visited, string& word){
            if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
                return false;
            
            if (visited[r][c]){
                return false;
            }
            
            if (!board[r][c]){
                return false;
            }
            if (board[r][c] != word[i]){
                return false;
            }
            if (i == word.length() - 1){
                return true;
            }
    
            visited[r][c] = true;
            bool found = (dfs(board, r+1, c, i+1, visited, word) || dfs(board, r-1, c, i+1, visited, word) || dfs(board, r, c+1, i+1, visited, word) || dfs(board, r, c-1, i+1, visited, word));
    
            visited[r][c] = false;
    
            return found;
        }
        
        bool exist(vector<vector<char>>& board, string word) {
            vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    
            for (int r = 0; r < board.size(); ++r){
                for (int c = 0; c < board[0].size(); ++c){
                    if(board[r][c] == word[0]){
                        if (dfs(board, r, c, 0, visited, word))
                            return true;
                    }
                }
            }
            return false;
        }
    };