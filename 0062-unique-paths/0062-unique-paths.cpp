// BOTTOM UP
class Solution {
public:
    
    vector<vector<int>> dp;
    
    int uniquePaths(int m, int n) {
        dp.clear();
        dp.resize(105,vector<int> (105,-1));
        
        for(int i = 0; i < m; i++){
            dp[i][n-1] = 1;
        }
        
        for(int j = 0; j < n; j++){
            dp[m-1][j] = 1;
        }
        
        for(int i = m-2; i>=0; i--){
            for(int j = n - 2; j >=0; j--){
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        
        return dp[0][0];
    }
};

// TOP DOWN
// class Solution {
// public:
    
//     vector<vector<int>> dp;
    
//     int f(int i, int j, int m, int n){

// // When it will reach destination, 1 will be returned
//         if(i == m - 1 && j == n - 1){
//             return 1;
//         }

//         if(dp[i][j] != -1) return dp[i][j];
// // Condition for checking if going out of grid or not
//         if(i >= m || i < 0 || j >= n|| j < 0){
//             return 0;
//         }

//         return dp[i][j] = f(i+1,j,m,n) + f(i,j+1,m,n);
//     }

//     int uniquePaths(int m, int n) {
//         dp.clear();
//         dp.resize(105,vector<int> (105,-1));
//         return f(0,0,m,n);
//     }
// };