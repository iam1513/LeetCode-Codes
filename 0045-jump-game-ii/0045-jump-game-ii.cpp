class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currMax = 0;
        int nextMax = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            
            // Calculating nextMax 
            nextMax = max(nextMax, i + nums[i]);

            
            // will update when we will reach the index where we can at max reach
            // when we will reach that index, then we will get kow the next index we can reavh as already stored in nextMax 
            if (i == currMax) {
                currMax = nextMax;
                jumps++;
            }
        }

        return jumps;
    }
};
