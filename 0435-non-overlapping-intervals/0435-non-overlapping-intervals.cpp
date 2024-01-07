 bool cmp(vector<int> a1, vector<int> a2){
        return a1[1] < a2[1];
 }

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt = 0;
        int lastPicked = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[lastPicked][1]>intervals[i][0]){
                cnt++;
            }
            else{
                lastPicked = i;
            }
        }
        
        return cnt;
    }
};