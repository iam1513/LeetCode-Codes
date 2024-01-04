class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int n = nums.size();
        
        unordered_map<int,int> m;
        
        for( auto ele: nums){
            m[ele]++;
        }
        
        int sum = 0;
        
        for( auto ele: m){
            if(ele.second == 1){
                return -1;
            }
            
            if(ele.second % 3 == 0 && ele.second!=0){
                sum += ele.second/3;
                ele.second = 0;
            }
            
            else if((ele.second % 3 == 2 && ele.second>1) || (ele.second % 3 == 1 && ele.second>1)){
                sum += ele.second/3 + 1;
                ele.second = 0;
            }
        }
        
        return sum;
    }
};


// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
        
//         int n = nums.size();
        
//         int maxe = INT_MIN;
        
//         for(int i = 0; i < n; i++){
//             if(nums[i]>maxe){
//                 maxe = nums[i];
//             }
//         }
        
                
//         vector<int> ans(maxe+1,0);
        
//         for(int i = 0; i < n; i++){
//             ans[nums[i]]++;
//         }
        
//         int sum = 0;
        
//         for(int i = 0; i < ans.size(); i++){
//             if(ans[i] == 1){
//                 return -1;
//             }
//         }
        
//         for(int i = 0; i < ans.size(); i++){
//             if(ans[i] % 3 == 0 && ans[i]!=0){
//                 sum += ans[i]/3;
//                 ans[i] = 0;
//             }
            
//             else if((ans[i] % 3 == 2 && ans[i]>1)|| (ans[i] % 3 == 1 && ans[i]>1)){
//                 sum += ans[i]/3 + 1;
//                 ans[i] = 0;
//             }
            
//         }
        
//         return sum;
//     }
// };