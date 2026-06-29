class Solution {
    public:
        vector<int> parent;
    
        int find(int x) {
            if (parent[x] == x) return x;
            //path compression
            parent[x] = find(parent[x]);
            return parent[x];
        }
    
        void unite(int a, int b) {
            int rootA = find(a);
            int rootB = find(b);
            parent[rootA] = rootB;
        }
        
        vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            parent.resize(edges.size() + 1);
    
            for (int i = 1; i <= edges.size(); ++i) {
                parent[i] = i;
            }
    
            for (int i = 0; i < edges.size(); ++i) {
                if (find(edges[i][0]) == find(edges[i][1])) {
                    return edges[i];
                }
    
                unite(edges[i][0], edges[i][1]);
            }
    
            return {};
        }
    };