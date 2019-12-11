//1.定义状态：到达(i, j)位置的路径上的所有数字之和最小值
//2.递推公式：F[i, j] = F[i - 1][j] + F[i][j - 1]
//3.初始化：第一行只能往右走，第一列只能往下走
//4.返回值：F[m - 1][n- 1]

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 1; i < m; i++){
            grid[i][0] += grid[i - 1][0];
        }
        
        for(int i = 1; i < n; i++){
            grid[0][i] += grid[0][i - 1];
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                int tmp = min(grid[i - 1][j], grid[i][j - 1]);
                grid[i][j] += tmp;
            }
        }
        
        return grid[m - 1][n - 1];
    }
};
