class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<pair<int,int>>> graph(n);
        
            for (auto& f : flights) {
                int from = f[0], to = f[1], price = f[2];
                graph[from].push_back({to, price});
            }
    
            vector<int> stops(n, INT_MAX);
            
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
            pq.push({0, src, 0});
    
            while(!pq.empty()){
                vector<int> curr = pq.top();
                pq.pop();
    
                int price = curr[0];
                int node = curr[1];
                int flightsUsed = curr[2];
    
                if (node == dst) return price;
    
                if (flightsUsed == k + 1) continue;
    
                if (flightsUsed >= stops[node]) continue;
                stops[node] = flightsUsed;
    
                for (auto [nei, weight] : graph[node]) {
                    pq.push({price + weight, nei, flightsUsed + 1});
                }
            }
    
            return -1;
        }
    };