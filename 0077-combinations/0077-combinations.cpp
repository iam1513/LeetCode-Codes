class Solution {
public:
    
    void combinations(int idx , int n, int cnt, int k, vector<int> v, vector<vector<int>>& ans, vector<int> nums){
        if(cnt == k){
            ans.push_back(v);
            return;
        }
        
        for( int i = idx; i < n; i++){
            v.push_back(nums[i]);
            combinations(i+1,n,cnt+1,k,v,ans,nums);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        int cnt = 0;
        vector<int> nums;
        for(int i = 1; i <=n; i++){
            nums.push_back(i);
        }
        combinations(0,n,cnt,k,v,ans,nums);
        
        return ans;
    }
};