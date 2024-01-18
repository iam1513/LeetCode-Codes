class Solution {
public:

    vector<vector<int>> dp;

    bool f(vector<int>& arr, int i , int k){
        if(k == 0) return true;

        if(i == arr.size()) return false;

        if(dp[i][k] != -1) return dp[i][k];

        if(arr[i]<=k){
            // Can include or exclude
            return  dp[i][k] = f(arr,i+1,k-arr[i]) || f(arr,i+1,k);
        }
        else{
            // Always exclude
            return  dp[i][k] = f(arr,i+1,k);
        }
    }

    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(int i = 0;i < nums.size(); i++) sum+=nums[i];
        if(sum%2==1) return false;

        dp.clear();
        dp.resize(205,vector<int>(20005,-1));

        return f(nums,0,sum/2);
        
    }
};