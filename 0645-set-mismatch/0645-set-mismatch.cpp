class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2,-1);
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> sol(nums.size()+1,0);
        
        for(int i = 0; i < n ;i++){
            sol[nums[i]]++;
        }
        
        for(int i = 1; i < n+1; i++){
            if(sol[i] == 0){
                ans[1] = i;
            }
            if(sol[i] == 2){
                ans[0] = i;
            }
        }
        
        return ans;
    }
};