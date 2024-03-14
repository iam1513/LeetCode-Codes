class Solution {
public:
    
    void f(int i, int j, vector<string> &ans, int n,string str){
        
        if(j>i){
            return ;
        }
        
        if(i==n && j == n){ 
            ans.push_back(str);
            return ;
        }
        
        if(i < n) {
            str += "(";
            f(i + 1, j, ans, n,str);
            str.pop_back();
        }
        if(j < n) {
            str += ")";
            f(i, j + 1, ans,n,str);
            str.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = "";
        f(0,0,ans,n,str);
        
        return ans;
        
    }
};