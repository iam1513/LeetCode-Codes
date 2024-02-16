class Solution {
public:
    
    void f(string digits,int i, string st, vector<string> &ans,vector<string> &v){
        if(i == digits.size()){
            ans.push_back(st);
            return;
        }
        
        int dig = digits[i] - '0';
        
        for(int j = 0; j < v[dig].size(); j++){
            f(digits,i+1,st+v[dig][j],ans,v);
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.size() == 0){
            return ans;
        }
        f(digits,0,"",ans,v);
        
        return ans;
    }
};