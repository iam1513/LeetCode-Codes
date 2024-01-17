class Solution {
public:
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<vector<int>> grid;
        int a = nums.size(); int m = l.size(); 
        vector<bool> ans;
        for(int i = 0; i < m; i++){
            vector<int> tmp ;
            for(int j = l[i]; j <= r[i]; j++){
                tmp.push_back(nums[j]);
            }
            grid.push_back(tmp);
        }
        
        for (auto& row : grid) {
            sort(row.begin(), row.end());
        }

        
        for(int i = 0; i < grid.size(); i++){
            bool isArth = true;
            for(int j = 1; j < grid[i].size() - 1; j++){
               if((grid[i][j] - grid[i][j-1]) != (grid[i][j+1] - grid[i][j])){
                   isArth = false;
                   break;
               }
            }
            ans.push_back(isArth);
            
        }
        
        
        return ans;
    }
};