class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentMaxReach = 0;
        int nextMaxReach = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            nextMaxReach = max(nextMaxReach, i + nums[i]);

            if (i == currentMaxReach) {
                currentMaxReach = nextMaxReach;
                jumps++;
            }
        }

        return jumps;
    }
};
