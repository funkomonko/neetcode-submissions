class Solution {
public:
    int climbStairs(int n) {
        long long one = 1, two = 1;
        for(int i = 0; i<n; i++){
            long long temp = one;
            one = one + two;
            two = temp;
        }

        return two;
    }
};