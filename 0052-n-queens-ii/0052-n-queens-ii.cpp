

class Solution {
public:
    
    bool canWePlace(vector<vector<string>> &ans, int n,int r, int c){
        
        for(int i = r-1,j=c-1; i>=0 && j>=0; i--,j-- ){
            if(ans[i][j] == "Q"){
                return false;
            }
        }
        
        for(int i = r-1,j=c+1; i>=0 && j<n; i--,j++ ){
            if(ans[i][j] == "Q"){
                return false;
            }
        }
        
        for(int j=c-1; j>=0;j-- ){
            if(ans[r][j] == "Q"){
                return false;
            }
        }
        
        for(int i=r-1; i>=0;i-- ){
            if(ans[i][c] == "Q"){
                return false;
            }
        }
        
        return true;
    }
    
    int f(vector<vector<string>> &ans, int n,int r){
        
        if(r==n){
           return 1;
        }
        
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(canWePlace(ans,n,r,j)){
                ans[r][j] = "Q";
                cnt += f(ans,n,r+1);
                ans[r][j] = ".";
            }
        }     
        
        return cnt;
        
    }
    
    int totalNQueens(int n) {
        vector<vector<string>> ans(n, vector<string> (n,"."));
        
        
        return f(ans,n,0);
        
    }
};