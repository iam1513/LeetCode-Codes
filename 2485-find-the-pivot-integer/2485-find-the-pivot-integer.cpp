class Solution {
public:
    int pivotInteger(int n) {
        int total_sum = 0;  //  sum of n natural no. : (n(n+1))/2;
        int left_sum = 0;

        int j = 1;
        while(j<=n){
            total_sum+=j;
            j++;
        }

        for(int i = 1; i <= n; i++){
            
            if(left_sum + i == total_sum){
                return i;
            }

            left_sum += i;
            total_sum -= i;
            
        }
        return -1;
    }
};