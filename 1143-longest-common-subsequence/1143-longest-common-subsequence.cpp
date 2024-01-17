class Solution {
public:
 // TOP DOWN    
    vector<vector<int>> dp;
    
    int f(string &text1, string &text2, int i, int j){ // If we wont pass it by ref, tle occurs , so pass it by ref as we are not doing any cahnges in string
        
        if(j == text2.size() || i == text1.size() ){
            return 0;
        }
        if(dp[i][j] != INT_MAX) return dp[i][j];
        if(text1[i] != text2[j]){
            return dp[i][j] =  max(f(text1,text2,i,j+1),f(text1,text2,i+1,j));
        }
        
        return dp[i][j] = 1+f(text1,text2,i+1,j+1);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        dp.clear();
        dp.resize(1005,vector<int> (1005,INT_MAX));
        
        
        return f(text1,text2,0,0);
        
        
    }
};