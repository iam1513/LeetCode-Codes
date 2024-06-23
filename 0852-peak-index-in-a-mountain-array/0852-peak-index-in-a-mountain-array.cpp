class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int first = 0; int last = arr.size() - 1;

        while(first<last){
            if(arr[first] > arr[last]){
                last--;
            }
            else if(arr[first] < arr[last]){
                first++; 
            }
            else{
                first++;last--;
            }
        }
        
        if(arr[first] > arr[last]){
            return first;
        }
        
        return last;

    }
};