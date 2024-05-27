class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> rows;
        vector<int> cols;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        
        for(int i = 0 ; i < r; i++){
            for(int j = 0; j < cols.size(); j++){
                int temp = cols[j];
                matrix[i][temp] = 0;
            }
        }
        
        for(int i = 0 ; i < rows.size(); i++){
            int temp = rows[i];
            for(int j = 0; j < c; j++){
                
                matrix[temp][j] = 0;
            }
        }
    }
};





















































// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int r = matrix.size();
//         int c = matrix[0].size();
//         vector<int> rows;
//         vector<int> cols;
        
//         for(int i = 0; i < r; i++){
//             for(int j = 0; j < c; j++){
//                 if(matrix[i][j] == 0){
//                     rows.push_back(i);
//                     cols.push_back(j);
//                 }
//             }
//         }
        
//         int n = rows.size(); int m = cols.size();
        
        
//         for(int i = 0; i < n; i++){
//             int k = rows[i];
//             for(int j = 0; j < c; j++){
//                 matrix[k][j] = 0;
//             }
//         }
        
//         for(int i = 0; i < r; i++){
//             for(int j = 0; j < m; j++){
//                 int k = cols[j];
//                 matrix[i][k] = 0;
//             }
//         }
//     }
// };


// // Won't work for negative inputs

// class Solution {
// public:
    
//     void setRow(vector<vector<int>> &matrix,int row, int c){
//         for(int i = 0; i < c; i++){
//             if(matrix[row][i] != 0){
//                 matrix[row][i]  = -1;
//             }
//         }
//     }
    
//     void setCol(vector<vector<int>> &matrix,int col, int r){
//         for(int i = 0; i < r; i++){
//             if(matrix[i][col] != 0){
//                 matrix[i][col]  = -1;
//             }
//         }
//     }
    
//     void setZeroes(vector<vector<int>>& matrix) {
//         int r = matrix.size();
//         int c = matrix[0].size();
        
//         for(int i = 0; i < r; i++){
//             for(int j = 0; j < c; j++){
//                 if(matrix[i][j] == 0){
//                     setRow(matrix,i,c);
//                     setCol(matrix,j,r);
//                 }
//             }
//         }
        
//         for(int i = 0; i < r; i++){
//             for(int j = 0; j < c; j++){
//                 if(matrix[i][j] == -1){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
        
//     }
// };