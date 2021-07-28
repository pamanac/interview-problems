//
// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
//

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int counter = 1;
        int end = n;
        int start = 0;
        for(int row=0; row<end; row++){
            int col = start;
            for(col = start; col < end; col++){
                matrix[row][col] = counter++;
            }
            int vert = row+1;
            col--;
            for(vert = row+1; vert < end; vert++){
                matrix[vert][col] = counter++;
            }
            vert--;
            if(row != end-1){
                for(int back = col-1; back >= start; back--){
                    matrix[vert][back] = counter++;
                }
                int up = vert-1;
                for(int up = vert-1; up > row; up--){
                    matrix[up][start] = counter++;
                }
                start++;
            }
            end--;
        }
        return matrix;
    }
};
