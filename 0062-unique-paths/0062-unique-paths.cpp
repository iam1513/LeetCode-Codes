class Solution {
public:
    
    vector<vector<int>> dp;
    
    int f(int i, int j, int m, int n){

// When it will reach destination, 1 will be returned
        if(i == m - 1 && j == n - 1){
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];
// Condition for checking if going out of grid or not
        if(i >= m || i < 0 || j >= n|| j < 0){
            return 0;
        }

        return dp[i][j] = f(i+1,j,m,n) + f(i,j+1,m,n);
    }

    int uniquePaths(int m, int n) {
        dp.clear();
        dp.resize(105,vector<int> (105,-1));
        return f(0,0,m,n);
    }
};