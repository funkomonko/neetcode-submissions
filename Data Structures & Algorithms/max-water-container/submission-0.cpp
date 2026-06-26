class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        
        int max_area = 0;
        for(int i = 0 ; i<n; i++){
            for(int j = i; j<n; j++){
                int ar = min(heights[i], heights[j])*(j-i);
                if(max_area<ar){
                    max_area = ar;
                }
            }
        }

        return max_area;
    }
};
