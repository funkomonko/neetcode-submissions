class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> revP;
        for(int i = 0; i<tokens.size(); i++){
            if(tokens[i] == "+"|| tokens[i] == "-"|| tokens[i] == "*"|| tokens[i] == "/"){
                int b = stoi(revP.top());
                revP.pop();
                int a = stoi(revP.top());
                revP.pop();

                if(tokens[i] == "+"){
                    revP.push(to_string(a+b));
                }
                else if(tokens[i] == "-"){
                    revP.push(to_string(a-b));
                }
                else if(tokens[i] == "*"){
                    revP.push(to_string(a*b));
                }
                else if(tokens[i] == "/"){
                    revP.push(to_string(a/b));
                }
            }
            else{
                revP.push(tokens[i]);
            }
        }
        return stoi(revP.top());
    }
};
