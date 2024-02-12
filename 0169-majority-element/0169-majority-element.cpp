class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(auto ele:nums){
            m[ele]++;
        }
        for(auto ele:m){
            if(ele.second > n/2){
                return ele.first;
            }
        }
        return -1;
    }
};