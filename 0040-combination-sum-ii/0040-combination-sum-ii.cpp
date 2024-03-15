class Solution {
public:
    
    void f(int idx, int sum, int target, vector<vector<int>>& ans, vector<int>& v, vector<int>& arr) {
        if (sum == target) {
            ans.push_back(v);
            return;
        }
        
        if (sum > target) {
            return;
        }
        
        // We have select every element and check whether it is included or not
        
        for (int i = idx; i < arr.size(); i++) {
            // i > idx, check to pick only first element and if repeated , we will ignore
            if (i > idx && arr[i] == arr[i - 1]) {
                continue;
            }
            v.push_back(arr[i]);
            f(i + 1, sum + arr[i], target, ans, v, arr);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        int sum = 0;
        int idx = 0;
        f(idx, sum, target, ans, v, candidates);
        
        return ans;
    }
};
