class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        
        int max_area = 0, left = 0, right = n-1;
        while(right>left){
            int area = min(heights[right], heights[left])*(right-left);

            if(area>max_area){
                max_area = area;
            }

            heights[right]>heights[left]?left++:right--;
        }

        return max_area;
    }
};
