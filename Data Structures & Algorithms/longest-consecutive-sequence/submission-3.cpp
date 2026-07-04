class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> check(nums.begin(), nums.end()); 
        int o = 0, maxSeq = 0;

        for(int i : check){
            if(check.find(i - 1) == check.end()){
                o = 1;
                while(check.find(i + o) != check.end()){
                    o++;
                }
                maxSeq = max(maxSeq, o);
            }
        }

        return maxSeq;
    }
};
