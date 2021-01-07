class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 0) return vector<vector<int>>();
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int up = 0;
        int left = 0;
        int down = n-1;
        int right = n-1;
        int count = 0;
        while (count < n*n) {
            //traverse right
            for (int j=left; j<=right && count<n*n; j++) {
                count++;
                matrix[up][j] = count;
            }
            //traverse down
            for (int i=up+1; i<=down && count<n*n; i++) {
                count++;
                matrix[i][right] = count;
            }
            //traverse left
            for (int j=right-1; j>=left && count<n*n; j--) {
                count++;
                matrix[down][j] = count;
            }
            //traverse up
            for (int i=down-1; i>up && count<n*n; i--) {
                count++;
                matrix[i][left] = count;
            }
            //adjust the pointers for next iteration
            up++;
            left++;
            right--;
            down--;
        }
        return matrix;
    }
};