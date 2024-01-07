class Solution {
public:
    
    vector<int> dp;
    
    int helper(int i,vector<int>& arr){
        if(i >= arr.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(arr[i]+helper(i+2,arr),helper(i+1,arr));
    }
    
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+10,-1);
        return helper(0,nums);
    }
};