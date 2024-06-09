class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int prefixSum = 0;
        int cnt = 0;
        
        for(int i = 0; i < nums.size() ; i++){
            prefixSum += nums[i];
            int rem = prefixSum - k;
            cnt += mp[rem];
            mp[prefixSum]++;
            
        }
        
        return cnt;
    }
};