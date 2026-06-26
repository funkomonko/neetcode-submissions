class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1; int prod0 = 1; vector <int> o;
        for(int i : nums){
            if(i == 0 && prod0 != 0){
                prod0 = 0;
            }
            else if(prod0 == 0){
                prod *= i;
                prod0 *= i;
            }
            else{
                prod *= i;
                prod0 *= i;
            }
        }
        if(prod0 != 0){
            for(int i : nums){
                o.push_back(prod/i);
            }
        }
        else{
            for(int i : nums){
                if(i == 0){
                    o.push_back(prod);
                }
                else{
                    o.push_back(prod0);
                }
            }
        }
        return o;
    }
};
