class Solution {
public:
    int am;
    int coinChange(vector<int>& coins, int amount) {
        am = amount;
        vector<int> dp(amount+1, -1);

        dp[amount] = 0;

        int result = coin(coins, 0, dp);
        return result == INT_MAX ? -1 : result;
    }

    int coin(vector<int>& coins, int i, vector<int> &dp){
        if(dp[i] != -1){
            return dp[i];
        }

        int res = INT_MAX;
        for(long long j : coins){
            if(j+i<=am){
                int min_coins = coin(coins, i + j, dp);
                
                if (min_coins != INT_MAX && min_coins < res) {
                    res = min_coins;
                }
            }
        }
        dp[i] = (res == INT_MAX) ? INT_MAX : res + 1;

        return dp[i];
    }
};
