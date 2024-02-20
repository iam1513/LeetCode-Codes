class Solution {
public:
    
    void toPush(vector<vector<string>> &ans, vector<vector<string>> &v, int n){
        vector<string> a;
        for(int i = 0; i < n; i++){
            string st = "";
            for(int j = 0; j < n; j++){
                st+=ans[i][j];
            }
            a.push_back(st);
        }
        
        v.push_back(a);
    }
    
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
    
    void f(vector<vector<string>> &ans, int n,int r, vector<vector<string>> &v){
        
        if(r==n){
            toPush(ans,v,n);
            return;
        }
        
        for(int j = 0; j < n; j++){
            if(canWePlace(ans,n,r,j)){
                ans[r][j] = "Q";
                f(ans,n,r+1,v);
                ans[r][j] = ".";
            }
        }     
        
        
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans(n, vector<string> (n,"."));
        vector<vector<string>> v;
        f(ans,n,0,v);
        return v;
    }
};