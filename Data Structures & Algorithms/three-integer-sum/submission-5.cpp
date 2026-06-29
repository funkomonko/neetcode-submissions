class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        map<vector<int>, int> m;
        vector<vector<int>> o;

        sort(nums.begin(), nums.end());
        for(int i = 0; i<n-1; i++){
            int left = i+1, right = n-1, t = -nums[i];
            while(left<right){
                int sum = nums[left] + nums[right];
                if(sum == t){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    m[temp]++;
                    left++;
                    right--;
                }
                else if(sum>t){
                    right--;
                }
                else if(sum<t){
                    left++;
                }
            }
        }        

        for(const auto& [key, value] : m){
            o.push_back(key);
        }
        return o;
    }
};
