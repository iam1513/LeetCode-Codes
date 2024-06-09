class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int ps = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int cnt = 0;
        
        for(int i = 0;i < nums.size() ; i++){
            // Take modulo twice to avoid negative remainders.
            ps = (nums[i]%k+ps+k)%k;
            if(mp.find(ps) != mp.end()){
                cnt = cnt + mp[ps];
            }
            
            mp[ps]++;
        }
        
        return cnt;
        
    }
};