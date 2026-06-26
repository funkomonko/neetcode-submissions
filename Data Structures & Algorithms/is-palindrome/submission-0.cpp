class Solution {
public:
    bool isPalindrome(string s) {
        string check, check2;
        for(int i = s.size() - 1; i>=0; i--){
            
            if(isalnum(s[i])){
                if(s[i]<'a'){
                    check += s[i] + 32;
                }
                else{
                    check += s[i];
                }
            }
        }

        for(int i = 0; i<s.size(); i++){
            
            if(isalnum(s[i])){
                if(s[i]<'a'){
                    check2 += s[i] + 32;
                }
                else{
                    check2 += s[i];
                }
            }
        }
        cout << check << " " << check2;

        return check == check2;
    }
};
