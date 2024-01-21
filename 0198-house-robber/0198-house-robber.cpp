// APPROACH 2 : DOWN-UP --> TAB

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1) return nums[n-1];
//         vector<int> dp(n+10,-1);
//         dp[n-1] = nums[n-1];
//         dp[n-2] = max(nums[n-1],nums[n-2]);
        
//         for(int i = n-3; i >=0; i--){
//             dp[i] = max(dp[i+2]+nums[i],dp[i+1]);
//         }
        
//         return dp[0];
//     }
// };



// APPROACH 1 : TOP-DOWN --> MEMO

// class Solution {
// public:
    
//     vector<int> dp;
    
//     int helper(int i,vector<int>& arr){
//         if(i >= arr.size()){
//             return 0;
//         }
//         if(dp[i]!=-1) return dp[i];
//         return dp[i] = max(arr[i]+helper(i+2,arr),helper(i+1,arr));
//     }
    
//     int rob(vector<int>& nums) {
//         dp.resize(nums.size()+10,-1);
//         return helper(0,nums);
//     }
// };


class Solution{
public:
    
    vector<int> a,dp;
    int n;
    
    int f(int i ){
        
        if(i>=n) return 0;
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        return dp[i] =  max(a[i] + f(i+2),f(i+1));
    }
    
    int rob(vector<int> &arr){
        n = arr.size();
        a = arr;
        
        dp.clear();
        dp.resize(105,-1);
        
        return f(0);
    }
};