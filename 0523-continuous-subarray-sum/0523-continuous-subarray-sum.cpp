class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int ps = 0;
        
        for(int i = 0; i < nums.size(); i++){
            ps =(nums[i]+ps)%k;
            
            if(mp.find(ps)!=mp.end()){
                if(i - mp[ps]>1){
                    return true;
                }
            }
            else{
                mp[ps] = i;
            }
        }
        
        return false;
    }
};