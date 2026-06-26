class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, pair <int, int>> m; int j = 0;
        for(int i= 0; i< nums.size(); i++){
            m[nums[i]].first++;
            m[nums[i]].second = i;
        }

        for(int i = 0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(m.find(diff)!=m.end() && m[diff].second != i){
                return {i, m[diff].second};
            }
        }
    }
};
