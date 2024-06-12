class Solution {
public:
    int rows; int cols; vector<vector<int>> temp;
    
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        temp = grid;
        int freshOranges = 0;
        queue<pair<int,int>> q;
        
        for(int i = 0; i< rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 2 ){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1 ){
                    freshOranges++;
                }
            }
        }
        
        q.push({-1,-1}); // Push after every level so we get to know that levels ends here
        int mins = 0;
        
        vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            if(f.first == -1 && f.second == -1){
                mins++;;
                if(!q.empty()){
                    q.push({-1,-1});
                }else{
                    break;
                }
            }
            else{
                int i = f.first;
                int j = f.second;
                for(int d = 0; d < 4; d++){
                    int nr = i + dir[d][0];
                    int nc = j + dir[d][1];
                    if(nr >= rows || nc >= cols || nr < 0 || nc < 0) continue;
                    if(grid[nr][nc] == 2 || grid[nr][nc] == 0) continue;
                    freshOranges--;
                    grid[nr][nc] = 2;
                    q.push({nr,nc});
                }
            }
        }
        
        return (freshOranges == 0) ? mins-1 : -1;
    }
    

};