class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), maxLength = 0, left = 0;
        unordered_set<char> seen;

        for(int right = 0; right<n; right++){
            while(seen.contains(s[right])){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[right]);
            maxLength = max((int)seen.size(), maxLength);
        }

        return maxLength;
    }
};
