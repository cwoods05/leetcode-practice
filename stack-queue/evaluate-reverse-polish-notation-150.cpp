class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> nums;
            int ans = 0;
            for(string& str : tokens){
                if(str == "+"){
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    ans = num2 + num1;
                    nums.push(ans);
                }
                else if(str == "-"){
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    ans = num2 - num1;
                    nums.push(ans);
                }
                else if(str == "*"){
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    ans = num2 * num1;
                    nums.push(ans);
                }
                else if(str == "/"){
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    ans = num2 / num1;
                    nums.push(ans);
                }
                else{
                    nums.push(std::stoi(str));
                }
            }
    
            return nums.top();
        }
    };