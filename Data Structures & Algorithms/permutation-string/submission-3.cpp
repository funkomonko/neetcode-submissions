class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int window = s1.size(), n = s2.size();

        map <char, int> s1count;
        for(char i : s1){
            s1count[i]++;
        }
        if(window<=n){
            for(int i = 0; i<=n-window; i++){
                map<char, int> s2count;
                for(int j = i; j<window+i; j++){
                    s2count[s2[j]]++;
                }
                if(s1count == s2count){
                    return true;
                }
            }
            return false;
        }
        else{
            return false;
        }
    }
};
