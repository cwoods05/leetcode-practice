class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
            
            int endTime = INT_MIN;
            int kept = 0;
    
            for(int i = 0; i < intervals.size(); ++i){
                if(intervals[i][0] >= endTime){
                    ++kept;
                    endTime = intervals[i][1];
                }
            }
    
            return (intervals.size() - kept);
        }
    };