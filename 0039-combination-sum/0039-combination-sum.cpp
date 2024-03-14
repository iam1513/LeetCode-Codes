class Solution {
public:
    
    void f(int idx, int sum, int target,vector<vector<int>>&  ans,vector<int>& v,vector<int>& arr){
        if(sum==target){
            ans.push_back(v);
            return;
        }
        
        if(sum>target || idx == arr.size()){
            return ;
        }
        
        v.push_back(arr[idx]);
        f(idx,sum+arr[idx],target,ans,v,arr);
        v.pop_back();
        f(idx+1,sum,target,ans,v,arr);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> v;
        int sum = 0;
        int idx = 0;
        f(idx,sum,target,ans,v,candidates);
        
        return ans;
        
    }
};