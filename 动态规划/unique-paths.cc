class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> numPath(m, vector<int>(n, 0));
        
        //第一列
        for(int i = 0; i < m; i++){
            numPath[i][0] = 1;
        }
        
        //第一行
        for(int i = 0; i < n; i++){
            numPath[0][i] = 1;
        }
        
        //每个位置只能从左边或者上边到达该位置
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                numPath[i][j] = numPath[i - 1][j] + numPath[i][j - 1];
            }
        }
        
        return numPath[m - 1][n - 1];
    }
};
