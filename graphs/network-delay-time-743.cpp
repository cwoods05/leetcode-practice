class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            vector<vector<pair<int,int>>> graph(n + 1);
    
            for (auto& t : times) {
                int u = t[0], v = t[1], w = t[2];
                graph[u].push_back({v, w});
            }
    
            vector<int> dist(n + 1, INT_MAX);
            dist[k] = 0;
    
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({0, k});
    
            while(!pq.empty()){
                auto [time, node] = pq.top();
                pq.pop();
    
                if (time > dist[node]) continue;
    
                for (auto [nei, weight] : graph[node]) {
                    if (time + weight < dist[nei]) {
                        dist[nei] = time + weight;
                        pq.push({dist[nei], nei});
                    }
                }
    
            }
    
            int ans = 0;
    
            for (int i = 1; i <= n; i++) {
                if (dist[i] == INT_MAX) return -1;
                ans = max(ans, dist[i]);
            }
    
            return ans;
        }
    };