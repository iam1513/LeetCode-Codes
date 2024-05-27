class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        
        for(int i = 0; i < numRows; i++){
            ans[i].resize(i+1);
            for(int j = 0; j <= i; j++){
                if(j == 0 || j == i){
                    ans[i][j] = 1;
                }
                
                else{
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
        }
        
        return ans;
        
        
    }
};



























































// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         int n = numRows;
//         vector<vector<int>> pascal(n);//vector with n rows
//         for(int i=0;i<n;i++){
//             pascal[i].resize(i+1);//first row have 1 column, row  2 have two column and so on
//             for(int j=0;j<i+1;j++){
//                 if(j == 0 || j== i){
//                     pascal[i][j] = 1;//first and last place will always have 1 
//                 }
//                 else{
//                     pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
//                 }
//             }
//         }
//             return pascal;
//         }
// };