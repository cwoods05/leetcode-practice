class Solution {
    public:
        bool isValid(string s) {
            stack<char> pancakes;
    
            for(char &c: s){
                if(c == '('){
                    pancakes.push(')');
                }
                else if(c == '['){
                    pancakes.push(']');
                }
                else if(c == '{'){
                    pancakes.push('}');
                }
                else{
                    if(pancakes.empty()){
                        return false;
                    } 
                    else{
                        if(c != pancakes.top()){
                            return false;
                        }
                    }
                    pancakes.pop();
                }
            }
    
            if(!pancakes.empty()){
                return false;
            }
    
            return true;
        }
    };
    