class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack <char> check;

        for(int i = 0; i<n; i++){
            if(s[i] == '[' || s[i] == '(' || s[i] == '{'){
                check.push(s[i]);
            }
            else if(!check.empty()){
                if(s[i] == ')'){
                    if(check.top() == '('){
                        check.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(s[i] == '}'){
                        if(check.top() == '{'){
                            check.pop();
                        }
                        else{
                            return false;
                        }
                    }
                    else if(s[i] == ']'){
                        if(check.top() == '['){
                            check.pop();
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
            else{
                return false;
            }
        }

        if(check.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
