class Solution {
    public:
        bool dfs(int course, vector<int>& state, vector<vector<int>>& adj) {
            if (state[course] == 1) return false; // found cycle
            if (state[course] == 2) return true;  // already checked
    
            state[course] = 1; // visiting
    
            for (int neighbor : adj[course]) {
                if (!dfs(neighbor, state, adj)) {
                    return false;
                }
            }
    
            state[course] = 2; // done
            return true;
        }
    
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> adj(numCourses);
    
            for (auto& p : prerequisites) {
                int course = p[0];
                int prereq = p[1];
                adj[prereq].push_back(course);
            }
    
            vector<int> state(numCourses, 0);
            // 0 = unvisited, 1 = visiting, 2 = done
    
            for (int i = 0; i < numCourses; i++) {
                if (state[i] == 0) {
                    if (!dfs(i, state, adj)) {
                        return false;
                    }
                }
            }
    
            return true;
        }
    };