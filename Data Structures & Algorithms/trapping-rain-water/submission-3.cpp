class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), o = 0, maxHp = height[0], maxHs = height[n-1];
        vector<int> prefix(n, 0), suffix(n, 0);

        for(int i = 0; i<n; i++){
            maxHp = max(maxHp, height[i]);
            maxHs = max(maxHs, height[n-1-i]);
            prefix[i] = maxHp;
            suffix[n-1-i] = maxHs; 
        }

        for(int i = 0; i<n; i++){
            o += min(prefix[i], suffix[i])- height[i];
        }
        return o;
    }
};
