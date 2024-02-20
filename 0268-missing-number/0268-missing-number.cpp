// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         unordered_map<int,int> m;
//         int n = nums.size();
//         for(auto ele : nums){
//             m[ele]++;
//         }

//         for(int i = 0; i <= n; i++){
//             if(m.find(i) == m.end()){
//                 return i;
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i = 0;
        while(i<n){
            if(nums[i] == i){
                i++;
            }
            else{
                return i;
            }
        }
        return n;
    }
};