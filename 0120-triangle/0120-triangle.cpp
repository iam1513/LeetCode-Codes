// class Solution {
// public:
    
// // TOP - DOWN   
    
    
//     // 2D dp
//     vector<vector<int>> dp;
//     // vector<vector<int>> grid;   //--> Can make global vector instead of passing by ref
    
//     int f(int r, int c ,vector<vector<int>>& triangle){
        
//         // Base case 
//         if(r == triangle.size() - 1){
//             return triangle[r][c];
//         }
        
//         if(dp[r][c] != -1) return dp[r][c];
        
//         return dp[r][c] = triangle[r][c] + min(f(r+1,c,triangle),f(r+1,c+1,triangle));
        
//     }
    
//     int minimumTotal(vector<vector<int>>& triangle) {
//         dp.clear();
//         dp.resize(205, vector<int> (205,-1));
//         // grid = triangle;
        
//         return f(0,0,triangle);
        
//     }
// };


// BOTTOM UP
class Solution {
public:
    
    vector<vector<int>> dp;
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        dp.clear();
        dp.resize(205, vector<int> (205,-1));
        
        int rows = triangle.size();
        
        for(int i = 0; i < triangle[rows-1].size(); i++){
            dp[rows-1][i] = triangle[rows-1][i];
        }
        
        for(int r = rows - 2; r >= 0 ; r--){
            for(int c =0 ; c < triangle[r].size(); c++){
                dp[r][c] = triangle[r][c] + min(dp[r+1][c], dp[r+1][c+1]);
            }
        }
        
        
        return dp[0][0];
    }
};