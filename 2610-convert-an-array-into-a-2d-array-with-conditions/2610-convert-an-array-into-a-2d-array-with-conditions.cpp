class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
// APPROACH 1 
        vector<vector<int>> ans;
        int n = nums.size();
        
        int maxe = nums[0];
        for(int i = 0; i < n; i++){
            if(maxe<nums[i]){
                maxe = nums[i];
            }
        }
        
        vector<int> v(maxe+1,0);
        
        for(int i = 0; i < n; i++)
        {
            v[nums[i]]++;
        }   
        
        for(int i = 0; i < n; i++){
            vector<int> a;
            int cnt = 0;
            for(int j = 0; j < maxe + 1; j++){
                if(v[j] > 0){
                    a.push_back(j);
                    v[j]--;
                }
                if(v[j] == 0){
                    cnt++;
                    if(cnt == maxe + 1){
                        break;
                    }
                }
            }
            if(a.size()!=0){
                ans.push_back(a);
            }     
        }
        
        return ans;
        

        
    }
};