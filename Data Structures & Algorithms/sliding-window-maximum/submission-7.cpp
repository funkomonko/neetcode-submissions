class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> q;
        vector<int> o(nums.size()-k+1);
        int l = 0, r = 0;

        while(r<nums.size()){
            while(!q.empty() && nums[q.back()] < nums[r]){
                q.pop_back();
            }
            q.push_back(r);

            if(l>q.front()){
                q.pop_front();
            }
            if((r+1)>=k){
                o[l] = nums[q.front()];
                l++;
            }
            r++;
        }
        return o;      
    }
};
