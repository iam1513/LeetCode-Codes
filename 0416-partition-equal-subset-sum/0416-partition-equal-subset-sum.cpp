class Solution {
public:
    
    int m = 0;
    vector<vector<int>> dp;

    void f(vector<int> &a, int n, int ans, int sum, int idx){

        if(idx == n){
            return ;
        }

        if(dp[idx][ans] != -1) {
            return;
        }

        if(ans == sum){
            m++;
            return ;
        }

        f(a, n, ans + a[idx], sum - a[idx], idx + 1);
        f(a, n, ans, sum, idx + 1);

        dp[idx][ans] = m;
    }
    
    bool canPartition(vector<int>& nums) {
        dp.clear();
         dp.resize(205,vector<int>(20005,-1));
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
           sum+=nums[i];
        }

        f(nums,n,0,sum,0);
        
        if(m>0){
            return true;
        }
        
        return false;
    }
};


// BOTTOM UP
// class Solution {
// public:

//     vector<vector<int>> dp;

//     bool canPartition(vector<int>& nums) {
        
//         int sum = 0;
//         int n = nums.size();
//         for(int i = 0;i < nums.size(); i++) sum+=nums[i];
//         if(sum%2==1) return false;
//         int k = sum/2;
//         dp.clear();
//         dp.resize(205,vector<int>(20005,false));

//         // for(int i = 0; i < n; i++) dp[i][0] = true;
//         dp[n][0] = true;
//         for(int i = n - 1; i >= 0; i--){
//             for(int j = 0; j <= k; j++){
//                 if(j==0) dp[i][j] = true;
//                 if(nums[i] <= j) {
//                     dp[i][j] = dp[i+1][j-nums[i]] || dp[i+1][j];
//                 }
//                 else{
//                     dp[i][j] = dp[i+1][j];
//                 }
//             }
//         }

//         return dp[0][k];
//     }
// };



// TOP DOWN

// class Solution {
// public:

//     vector<vector<int>> dp;

//     bool f(vector<int>& arr, int i , int k){
//         if(k == 0) return true;

//         if(i == arr.size()) return false;

//         if(dp[i][k] != -1) return dp[i][k];

//         if(arr[i]<=k){
//             // Can include or exclude
//             return  dp[i][k] = f(arr,i+1,k-arr[i]) || f(arr,i+1,k);
//         }
//         else{
//             // Always exclude
//             return  dp[i][k] = f(arr,i+1,k);
//         }
//     }

//     bool canPartition(vector<int>& nums) {
        
//         int sum = 0;
//         for(int i = 0;i < nums.size(); i++) sum+=nums[i];
//         if(sum%2==1) return false;

//         dp.clear();
//         dp.resize(205,vector<int>(20005,-1));

//         return f(nums,0,sum/2);
        
//     }
// };