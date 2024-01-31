class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int cnt_0 = 0;
        int prod = 1;
        vector<int> idx;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                cnt_0++;
                idx.push_back(i);
            }
            if(nums[i] != 0){
                prod *= nums[i];
            }
        }
        
        
        if(cnt_0>1){
            vector<int> ans(nums.size(),0);
            return ans;
        }
        
        if(cnt_0 == 1){
            vector<int> ans(nums.size(),0);
            int j = idx[0];
            ans[j] = prod;
            
            return ans;
        }
        
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++){
            ans.push_back(prod/nums[i]);
        }
        
        return ans;
    }
};