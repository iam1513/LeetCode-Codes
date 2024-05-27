class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans = INT_MIN;
        int sum = 0;
        
        for(int i = 0; i < nums.size() ; i++){
            sum+=nums[i];
            ans = max(sum, ans);
            
            if(sum<0){
                sum = 0;
            }
        }
        
        return ans;
    }
};

























































// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         int maxSum = INT_MIN;
//         for(int i = 0; i < n; i++){
//             sum += nums[i];
//             if(sum > maxSum){
//                 maxSum = sum;
//             }

//             if(sum<0){
//                 sum = 0;
//             }
//         }

//         return maxSum;
//     }
// };
