class Solution {
public:

    vector<vector<int>> grid,dp;

    int f(int i , int j){
        if((i == grid.size()-1) && (j == grid[0].size() - 1)){
            return 1;
        }   

        if(i >= grid.size()|| i < 0 || j >= grid[0].size() || j<0){
            return 0;
        }

        if(grid[i][j] == 1){
            return 0;
        }     
        if(dp[i][j]!= -1) return dp[i][j];
        return dp[i][j] = f(i+1,j) + f(i,j+1);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        dp.clear();
        dp.resize(105,vector<int> (105,-1));
        if(grid[grid.size()-1][grid[0].size()-1] == 1) return 0;
        return f(0,0);
    }
};