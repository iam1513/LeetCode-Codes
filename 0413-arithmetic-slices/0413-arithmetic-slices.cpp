class Solution {
public:
    
    vector<int> dp;
    
    int f(int c){
        if(c == 1) return 1;
        
        if (dp[c] != -1) {return dp[c];}
        return dp[c] = c+f(c-1);
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        dp.clear();
        dp.resize(5005,-1);
        
        vector<int> ans;
        
        for(int i = 1; i < nums.size(); i++){
            ans.push_back(nums[i] - nums[i-1]);
        }
        
        int cnt = 0;
        int sol = 0;
        int ptr1 = 0; int ptr2 = 1;
        
        while (ptr2 <= ans.size()) {
            if (ptr2 == ans.size() || ans[ptr1] != ans[ptr2]) {
                cnt = ptr2 - ptr1;
                ptr1 = ptr2;
                ptr2 = ptr1 + 1;
                if (cnt > 1) {
                    sol = sol + f(cnt - 1);
                }
            } else {
                ptr2++;
            }
        }
        
        return sol;
    }
};