class Solution {
public:
    
    int n,m;
    vector<vector<int>> dp;
       
    int f(int i, int j, vector<vector<int>> & grid){
        
        if(i == n -1 && j == m - 1) return grid[n-1][m-1];
        
        if(i >= n || j>= m || j< 0 || i <0) return INT_MAX;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = grid[i][j] + min(f(i+1,j,grid),f(i,j+1,grid));
    }

    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.clear();
        dp.resize(205,vector<int> (205,-1));
        return f(0,0,grid);
    }
};