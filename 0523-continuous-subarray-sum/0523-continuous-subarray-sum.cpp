class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 0; // Initialize with 0 to handle subarray starting from index 0
        int ps = 0; // Prefix sum

        for(int i = 0; i < nums.size(); i++) {
            ps += nums[i];
            int psm = ps % k; // Prefix sum modulo k
            
            // Handle negative modulo result
            if (psm < 0) {
                psm += k;
            }
            
            if (mp.find(psm) != mp.end()) {
                // If the subarray length is greater than 1
                if (i + 1 - mp[psm] > 1) {
                    return true;
                }
            } else {
                mp[psm] = i + 1;
            }
        }
        
        return false;
    }
};
