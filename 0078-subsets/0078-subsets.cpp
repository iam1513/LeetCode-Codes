class Solution {
public:
    
    void f(int idx, vector<int> a, vector<int> v, vector<vector<int>> &ans){

    if(idx == a.size()){
        return ;
    }

    for(int i = idx;i < a.size(); i++){
        v.push_back(a[i]);
        ans.push_back(v);
        f(i+1,a,v,ans);
        v.pop_back();
    }
}
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        // vector<int> a = {1,2,3};
        vector<vector<int>> ans;
        ans.push_back({});
        vector<int> v;

    f(0,nums,v,ans);
        
        return ans;
    }
};