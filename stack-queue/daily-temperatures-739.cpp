class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            stack<int> ind;
            vector<int> answers(temperatures.size(), 0);
    
            for(int i = 0; i < temperatures.size(); ++i){
                int current = temperatures[i];
    
                while(!ind.empty() && current > temperatures[ind.top()]){
                    int oldIndex = ind.top();
                    ind.pop();
                    answers[oldIndex] = i - oldIndex;
                }
    
                ind.push(i);
            }
    
            return answers;
        }
    };