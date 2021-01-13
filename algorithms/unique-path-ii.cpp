class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        bool x_blocked = false;
        bool y_blocked = false;
        
        //check for obstacles in first row
        for (int j=0; j<n && x_blocked == false; j++){
            if (obstacleGrid[0][j] != 0) {
                x_blocked = true;
            }
            dp[0][j] = obstacleGrid[0][j] == 0 ? 1:0;
        }
        //check for obstacles in first col
        for (int i=0; i<m && y_blocked == false; i++){
            if (obstacleGrid[i][0] != 0) {
                y_blocked = true;
            }
            dp[i][0] = obstacleGrid[i][0] == 0 ? 1:0;
        }
        
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                if (obstacleGrid[i][j] != 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = (obstacleGrid[i][j-1] == 0 ? dp[i][j-1]:0) 
                                + (obstacleGrid[i-1][j] == 0 ? dp[i-1][j]:0);
                }
                // cout << "dp["<<i<<"]["<<j<<"]: " << dp[i][j] << endl;
            }
        }
        return dp[m-1][n-1];
    }
};