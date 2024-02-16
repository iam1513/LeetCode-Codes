class Solution {
public:
    
    void f(vector<int> &nums, int idx, int n, vector<vector<int>> &ans,vector<int> a){
        
        if(idx == n){
            ans.push_back(a);
            return ;
        }
        
        a.push_back(nums[idx]);
        f(nums,idx+1,n,ans,a);
        a.pop_back();
        f(nums,idx+1,n,ans,a);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> a;
        f(nums,0,nums.size(),ans,a);
        
        return ans;
    }
};