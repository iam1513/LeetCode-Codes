class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int ps = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int cnt = 0;
        
        for(int i = 0;i < nums.size() ; i++){
            ps += nums[i];
            int psm = ps % k; 
            
            if (psm < 0) {
                psm += k;
            }
            if(mp.find(psm) != mp.end()){
                cnt = cnt + mp[psm];
            }
            
            mp[psm]++;
        }
        
        return cnt;
        
    }
};