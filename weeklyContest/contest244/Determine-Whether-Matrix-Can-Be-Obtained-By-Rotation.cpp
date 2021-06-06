//problem link-> https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
class Solution{
  //no need of explation in it..
    public:
        void rotateMatrix(vector<vector<int>> &mat,int N)
{
    // Consider all squares one by one
    for (int x = 0; x < N / 2; x++) {
        // Consider elements in group
        // of 4 in current square
        for (int y = x; y < N - x - 1; y++) {
            // Store current cell in
            // temp variable
            int temp = mat[x][y];

            // Move values from right to top
            mat[x][y] = mat[y][N - 1 - x];

            // Move values from bottom to right
            mat[y][N - 1 - x]
                = mat[N - 1 - x][N - 1 - y];

            // Move values from left to bottom
            mat[N - 1 - x][N - 1 - y]
                = mat[N - 1 - y][x];

            // Assign temp to left
            mat[N - 1 - y][x] = temp;
        }
    }
}
        bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
            int n = mat.size();
            if(mat == target) return true;
            for(int i=0;i<4;i++){
                rotateMatrix(mat,n);
                if(mat==target) return true;
            }
            return false;
        }
};
