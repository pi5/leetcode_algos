class Solution {
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            int rows = matrix.size();
            int cols = matrix[0].size();

            /* Start from top right corner */
            int r = 0;
            int c = cols - 1;

            while (r < rows && c >= 0) {

                if (matrix[r][c] == target) {
                    return true;
                }
                else if (matrix[r][c] > target) {
                    /* if value in matrix is greater, decrease column */
                    c--;
                }
                else if (matrix[r][c] < target) {
                    /* if value in matrix is smaller, increase row */
                    r++;
                }
            }

            /* value not found */
            return false;
        }
};
