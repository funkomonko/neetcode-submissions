class Solution {
public:
    string longestPalindrome(string s) {
        int resL = 0;
        string res;
        for(int i = 0; i<s.size(); i++){
            int l = i, r = i;
            while(l >=0 && r <s.size() && s[l] == s[r]){
                if(resL<(r-l+1)){
                    resL = (r-l+1);
                    res = s.substr(l, resL);
                }
                l--;
                r++;
            }

            l = i, r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(resL < (r-l+1)){
                    resL = r-l+1;
                    res = s.substr(l, resL);
                }
                l--;
                r++;
            }
        }
        
        return res;
    }
};
