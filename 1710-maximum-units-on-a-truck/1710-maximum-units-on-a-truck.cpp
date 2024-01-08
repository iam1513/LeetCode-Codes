bool to_sort(vector<int> a1, vector<int> a2)
{
    return a1[1] > a2[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int r = boxTypes.size();
        // int c = boxTypes[0].size();
        // for(int i = 0; i < r; i++){
        //     for(int j = 0; j < c; j++){
        //         cout<<boxTypes[i][j]<<" ";
        //     }cout<<endl;
        // }
        
        // Sort on the basis of no of units in descending order
        sort(boxTypes.begin(),boxTypes.end(),to_sort);
        int ans = 0;
        
        int i;
        
        for (int i = 0; i < r; i++) {
            if (boxTypes[i][0] <= truckSize) {
                ans += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else {
                ans += truckSize * boxTypes[i][1];
                break;
            }
        }
        
        
        return ans;
    }
};