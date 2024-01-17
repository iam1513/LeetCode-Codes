class Solution {
public:
    
   
    
    
    // 2D dp
    vector<vector<int>> dp;
    // vector<vector<int>> grid;   //--> Can make global vector instead of passing by ref
    
    int f(int r, int c ,vector<vector<int>>& triangle){
        
        // Base case 
        if(r == triangle.size() - 1){
            return triangle[r][c];
        }
        
        if(dp[r][c] != -1) return dp[r][c];
        
        return dp[r][c] = triangle[r][c] + min(f(r+1,c,triangle),f(r+1,c+1,triangle));
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        dp.clear();
        dp.resize(205, vector<int> (205,-1));
        // grid = triangle;
        
        return f(0,0,triangle);
        
    }
};