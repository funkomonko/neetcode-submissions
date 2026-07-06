class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()-1, m = (l+r)/2;
        while(l<=r){
            m = (l+r)/2;
            if(matrix[m][0]>target){
                r = m - 1;
            }
            else if(matrix[m][0]<target){
                l = m + 1;
            }
            else if (matrix[m][0] == target){
                return true;
            }
        }
        m = (l+r)/2;
        l = 0; r = matrix[m].size()-1; int mid = (l+r)/2;

        while(l<=r){
            mid = (l+r)/2;
            if(matrix[m][mid]>target){
                r = mid - 1;
            }
            else if(matrix[m][mid]<target){
                l = mid + 1;
            }
            else if(matrix[m][mid] == target){
                return true;
            }
        }

        return false;
    }
};
