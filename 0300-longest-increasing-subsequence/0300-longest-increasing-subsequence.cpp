class Solution {
public:
    
    vector<int> arr;
    vector<int> dp;
    
    int f(int i){
        
        if(i == 0) return 1;
        
        int maxe = INT_MIN;
        
        if(dp[i] != -1) return dp[i];
        
        for(int j = 0; j <= i - 1; j++){
            if(arr[j] < arr[i]){
                // Checking max between prev sub seq
                maxe = max(maxe,f(j));
            }
        }
        
        if(maxe == INT_MIN) {
            return dp[i] = 1;
        }
        
        return dp[i] = 1 + maxe; // returning prev maximum + 1(number itself)
    }
    
    int lengthOfLIS(vector<int>& nums) {
        dp.clear();
        dp.resize(2505,-1);
        arr = nums;
        
        dp[0] = 1;
        int ans = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            ans = max(ans,f(i));
        }
        
        return ans;
    }
};