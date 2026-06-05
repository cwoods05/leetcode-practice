class TimeMap {
    private: 
        unordered_map<string, vector<pair<int, string>>> mp;
        
    public:
        TimeMap() {
    
        }
        
        void set(string key, string value, int timestamp) {
            pair<int, string> pear = {timestamp, value};
            mp[key].push_back(pear);
        }
        
        string get(string key, int timestamp) {
            if (!mp.count(key)) return "";
    
            auto& vec = mp[key];
    
            int left = 0;
            int right = vec.size() - 1;
            int largestIndex = -1;
    
            while (left <= right) {
                int mid = left + (right - left) / 2;
    
                if (vec[mid].first <= timestamp) {
                    largestIndex = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
    
            if (largestIndex == -1) return "";
    
            return vec[largestIndex].second;
        }
    };
    
    /**
     * Your TimeMap object will be instantiated and called as such:
     * TimeMap* obj = new TimeMap();
     * obj->set(key,value,timestamp);
     * string param_2 = obj->get(key,timestamp);
     */