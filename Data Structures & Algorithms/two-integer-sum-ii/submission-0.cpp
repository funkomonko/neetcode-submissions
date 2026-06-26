class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), right = n-1, left = 0;

        while(right>left){
            int sum = numbers[left] + numbers[right];

            if(sum>target){
                right--;
            }
            else if(sum<target){
                left++;
            }
            else if(sum == target){
                break;
            }
        }

        return {left+1, right+1};
    }
};
