class Solution {
public:
    
    int f(vector<vector<int>>& board, int i, int j){
        int r = board.size();
        int c = board[0].size();
        int cnt = 0;
        
        if(i-1>=0 && j-1>=0 && board[i-1][j-1] == 1){
            cnt++;
        }
        
        if(i-1>=0 && j+1<c && board[i-1][j+1] == 1){
            cnt++;
        }
        
        if(i+1<r && j+1<c && board[i+1][j+1] == 1){
            cnt++;
        }
        
        if(i+1<r && j-1>=0 && board[i+1][j-1] == 1){
            cnt++;
        }
        
        if(i-1>=0 &&  board[i-1][j] == 1){
            cnt++;
        }
        
        if(j-1>=0 &&  board[i][j-1] == 1){
            cnt++;
        }
        
        if(i+1<r &&  board[i+1][j] == 1){
            cnt++;
        }
        
        if(j+1<c &&  board[i][j+1] == 1){
            cnt++;
        }
        
        return cnt;
    }

    void gameOfLife(vector<vector<int>>& board) {

        int rows = board.size();
        int cols = board[0].size();
        
        
        vector<vector<int>> a = board;
        
        for(int i =0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int cnt = f(a, i, j);
                
                if(a[i][j] == 1 && cnt < 2){
                    board[i][j] = 0;
                }
                
                else if(a[i][j] == 1 && (cnt > 3)){
                    board[i][j] = 0;
                }
                
                else if(a[i][j] == 0 && cnt==3){
                    board[i][j] = 1;
                }
                
                else if(a[i][j] == 1 && (cnt==2 || cnt==3)){
                    board[i][j] = 1;
                }
            }
        }
        
        // for(int i = 0; i < rows; i++){
        //     for(int j = 0; j < cols;j++){
        //         board[i][j] = a[i][j];
        //     }
        // }
    }
};
