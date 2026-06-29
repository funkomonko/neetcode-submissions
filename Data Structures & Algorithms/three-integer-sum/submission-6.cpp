class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> o;

        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;

            int left = i+1, right = n-1, t = -nums[i];
            while(left<right){
                int sum = nums[left] + nums[right];
                if(sum == t){
                    o.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
                else if(sum>t){
                    right--;
                }
                else if(sum<t){
                    left++;
                }
            }
        }
        return o;
    }
};
