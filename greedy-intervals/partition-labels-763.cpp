class Solution {
    public:
        vector<int> partitionLabels(string s) {
            // last[i] = last occurrence of character ('a' + i)
            vector<int> last(26);
    
            for (int i = 0; i < s.size(); i++) {
                last[s[i] - 'a'] = i;
            }
    
            vector<int> result;
            int start = 0;
            int end = 0;
    
            for (int i = 0; i < s.size(); i++) {
                end = max(end, last[s[i] - 'a']);
    
                if (i == end) {
                    result.push_back(end - start + 1);
                    start = i + 1;
                }
            }
    
            return result;
        }
    };