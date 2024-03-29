class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        int ptr1 = 0; int ptr2 = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                ans.push_back(pos[ptr1]);
                ptr1++;
            }
            else{
                ans.push_back(neg[ptr2]);
                ptr2++;
            }
        }
        
        return ans;
    }
};