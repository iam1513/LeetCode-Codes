class Solution {
public:
    
    vector<int> dp;
    
    int string_to_int(string s){
        if(s.size() == 1) return s[0] - '0'; // String to int conversion
        return ((s[0] - '0')*10 + (s[1] - '0')); // returning 2 digit int
    }
    
    int helper(int idx, string s){
        
        if(s[idx] == '0') return 0;
        if(idx>=s.size()) return 0;
        
        if(idx == s.size()-1){
            if(s[idx] =='0') return 0;
            else return 1;
        }
        
        if(idx == s.size() - 2){
            bool can_form_2_dig = string_to_int(s.substr(idx,2)) <= 26;
            return can_form_2_dig + helper(idx+1,s);
        }
        
        if(dp[idx] != -1) return dp[idx];
        
        bool can_form_2_dig = string_to_int(s.substr(idx,2)) <= 26; // Passing substring of length 2 and checking if its smaller than 26 or not
        
        return dp[idx] = helper(idx+1,s) + ((can_form_2_dig) ? helper(idx+2,s) : 0);
        
    }
    
    int numDecodings(string s) {
        dp.clear(); // To remove garbage values if any
        dp.resize(105,-1);
        return helper(0,s);
    }
};