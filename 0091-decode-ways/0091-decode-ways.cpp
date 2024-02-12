class Solution {
public:
    
    vector<int> dp;
    
    int string_to_int(string s){
        if(s.size() == 1){
            return s[0] - '0';
        }
        
        else{
            return (s[0] - '0')*10 + (s[1]- '0');
        }
    }
    
    int ways(string str, int idx){
        
        if(str[idx] == '0') return 0;
        
        if(idx>=str.size()) return 0;
        
        if(idx == str.size() - 1){
            if(str[idx]=='0') return 0;
            else{
                return 1;
            }
        }
        
        if(idx == str.size() - 2){
            bool can_form_2_dig = string_to_int(str.substr(idx,2)) <= 26;
            return can_form_2_dig +ways(str,idx+1);
        }
        
        if(dp[idx] != -1) return dp[idx];
        
        bool can_form_2_digits = string_to_int(str.substr(idx,2)) <= 26;
        
        return dp[idx]  = ways(str,idx+1) + (can_form_2_digits ? ways(str,idx+2) : 0);
        
    }
    
    int numDecodings(string s) {
        dp.clear();
        dp.resize(105,-1);
        
        return ways(s,0);
    }
};