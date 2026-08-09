class Solution {
public:
    int rob(vector<int>& nums) {
        return max(nums[0], max(robber(nums, true), robber(nums, false)));
    }

    int robber(vector<int>&nums, bool end){
        int rob1 = 0, rob2 = 0;
        if(end){
            for(int i = 0; i<nums.size()-1; i++){
                int temp = max(rob1+nums[i], rob2);
                rob1 = rob2;
                rob2 = temp;
            }

            return rob2;
        }
        else{
            for(int i = 1; i<nums.size(); i++){
                int temp = max(rob1 + nums[i], rob2);
                rob1 = rob2;
                rob2 = temp;
            }

            return rob2;
        }
    }
};
