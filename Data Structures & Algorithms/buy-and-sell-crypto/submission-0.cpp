class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, left = 0, n = prices.size(), minval = prices[0];

        for(int right = 1; right<n; right++){
            int profit = prices[right] - prices[left];

            if(prices[right]<minval){
                minval = prices[right];
                left = right;
            }
            maxP = max(maxP, profit);
        }
        
        if(maxP>0){
            return maxP;
        }
        else{
            return 0;
        }
    }
};
