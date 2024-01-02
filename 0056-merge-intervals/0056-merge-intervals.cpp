class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        if (intervals.empty()) {
            return ans;
        }

        sort(intervals.begin(), intervals.end());

        int ptr1 = intervals[0][0];
        int ptr2 = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            if (currentStart <= ptr2) {
                // Merge intervals
                ptr2 = max(ptr2, currentEnd);
            } else {
                // Add the merged interval to the result and update ptrs
                ans.push_back({ptr1, ptr2});
                ptr1 = currentStart;
                ptr2 = currentEnd;
            }
        }

        // Adding last interval
        ans.push_back({ptr1, ptr2});

        return ans;
    }
};
