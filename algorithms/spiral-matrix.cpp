class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0) return result;
        int r = matrix.size();
        int c = matrix[0].size();
        int up = 0;
        int left = 0;
        int down = r-1;
        int right = c-1;
        while (result.size() < r*c) {
           //traverse right
            for (int j=left; j<=right && result.size()<r*c; j++){
                result.push_back(matrix[up][j]);
            }
            //traverse down
            for (int i=up+1; i<=down && result.size()<r*c; i++){
                result.push_back(matrix[i][right]);
            }
            //traverse left
            for (int j=right-1; j >= left && result.size()<r*c; j--){
                result.push_back(matrix[down][j]);
            }
            //traverse up
            for (int i=down-1; i > up && result.size()<r*c; i--){
                result.push_back(matrix[i][left]);
            }
            //adjust the pointers for next iteration
            up++;
            left++;
            right--;
            down--;
        }
        return result;
    }
};