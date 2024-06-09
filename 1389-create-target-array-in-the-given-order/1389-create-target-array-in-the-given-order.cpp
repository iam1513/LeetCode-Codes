class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> target;
        
        
        for(int i = 0; i < n; i++){
            int idx = index[i];
            int num = nums[i];
            target.insert(target.begin() + idx, num); // Vector, how to insert element at a postion 
        }

        return target;

    }
};