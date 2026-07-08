class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end()), mid = (l+r)/2, res = r;
        while(l<=r){
            mid = (l+r)/2;
            int check = 0;
            for(int i = 0; i<piles.size(); i++){
                check += (piles[i]+mid-1)/mid;
            }
            if(check > h){
                l = mid + 1;
            }
            else if (check<=h){
                res = min(res, mid);
                r = mid - 1;
            }
        }

        return res;
    }
};
