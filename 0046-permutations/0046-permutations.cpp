class Solution {
public:
    
    
    void f(int i, vector<int>& v, vector<vector<int>> &ans ){
        
        if(i == v.size()-1){
            ans.push_back(v);
            return;
        }
        
        for(int j = i; j < v.size(); j++){
            swap(v[i],v[j]);
            f(i+1,v,ans);
            swap(v[i],v[j]);
            
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        f(0,nums,ans);
        
        return ans;
        
    }
};