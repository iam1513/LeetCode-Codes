// class Solution {
// public:
//     int m, n;
//     vector<vector<int>> grid, dp;

//     int f(int i, int j) {
//         if (i == m) {
//             return 0;
//         }

//         if (i >= m || j >= n || i < 0 || j < 0) {
//             return INT_MAX;
//         }

//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }

//         dp[i][j] = grid[i][j] + min({f(i + 1, j), f(i + 1, j - 1), f(i + 1, j + 1)});

//         return dp[i][j];
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         grid = matrix;
//         m = grid.size();
//         n = grid[0].size();

//         dp.clear();
//         dp.resize(105, vector<int>(105, -1));

//         int result = INT_MAX;
//         for (int j = 0; j < n; j++) {
//             result = min(result, f(0, j));
//         }

//         return result;
//     }
// };


// FILLING ARRAY DOWN TO UP

class Solution {
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, std::vector<int>(n, 0));

        // Setting up base condition for base case
        for (int j = 0; j < n; j++) {
            dp[n-1][j] = matrix[n-1][j];
        }

        // Build the dp table from bottom to top
        for (int i = n-2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int b_l = INT_MAX;
                int b_r = INT_MAX;
                if(j-1 >= 0)  b_l = dp[i+1][j-1];
                int b = dp[i+1][j];
                if(j+1 < n) b_r = dp[i+1][j+1];
                
                dp[i][j] = matrix[i][j] + min({b_l, b, b_r});
            }
        }

        // Find the minimum value in the top row, which represents the minimum falling path sum
        int res = INT_MAX;
        for (int j = 0; j < n; j++) {
            res = min(res, dp[0][j]);
        }

        return res;
    }
};

