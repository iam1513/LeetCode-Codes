class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int cnt = 0;
        
        for(int r = 0; r < rows ;r++){
            for(int c = 0; c < cols ;c++){
                if(grid[r][c] == '0' ){
                    continue;
                }
                // If already visited
                if(grid[r][c] == '0'){
                    continue;
                }
                cnt++;
                grid[r][c] = '0';
                queue<pair<int,int>> qu;
                qu.push({r,c});
                while(!qu.empty()){
                    auto curr = qu.front();
                    qu.pop();
                    int currrRow = curr.first;
                    int currrCol = curr.second;
                    
                    
                    if(currrRow - 1 >= 0 && grid[currrRow - 1][currrCol] =='1'){
                        qu.push({currrRow - 1,currrCol});
                        grid[currrRow - 1][currrCol] ='0';
                    }
                    if(currrRow+1 < rows && grid[currrRow + 1][currrCol] =='1'){
                        qu.push({currrRow + 1,currrCol});
                        grid[currrRow + 1][currrCol] ='0';
                    }
                    if(currrCol - 1 >= 0 && grid[currrRow ][currrCol - 1] =='1'){
                        qu.push({currrRow ,currrCol-1});
                        grid[currrRow][currrCol-1] ='0';
                    }if(currrCol + 1 < cols && grid[currrRow ][currrCol+1] =='1'){
                        qu.push({currrRow ,currrCol+1});
                        grid[currrRow][currrCol+1] ='0';
                    }
                }
            }
        }
        return cnt;
    }
};