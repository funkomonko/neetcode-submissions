class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> minNext;
        int n = heights.size();
        vector<int> nextSmall(heights.size(), 0), prevSmall(heights.size(), 0);
        for(int i = 0; i<n; i++){
            if(!minNext.empty() && minNext.top().first>heights[i]){
                while(!minNext.empty() && minNext.top().first>heights[i]){
                    nextSmall[minNext.top().second] = i;
                    minNext.pop();
                }
            }
            minNext.push({heights[i], i});
        }
        while(!minNext.empty()){
            nextSmall[minNext.top().second] = n;
            minNext.pop();
        }
        for(int i = n-1; i>=0; i--){
            if(!minNext.empty() && minNext.top().first>heights[i]){
                while(!minNext.empty() && minNext.top().first>heights[i]){
                    prevSmall[minNext.top().second] = i;
                    minNext.pop();
                }
            }
            minNext.push({heights[i], i});
        }
        while(!minNext.empty()){
            prevSmall[minNext.top().second] = -1;
            minNext.pop();
        }
        int res = 0;
        for(int i = 0; i<n; i++){
            int area = (nextSmall[i]-prevSmall[i]-1)*heights[i];
            res = max(area, res);
        }

        return res;
    }
};
