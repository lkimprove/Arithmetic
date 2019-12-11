//1.定义状态：到达(i, j)的路径和；
//2.递推公式：F[i][j] = F[i - 1][j] + F[i][j - 1]；
//3.初始值：第一行和第一列均为1
//4.返回值：F[m - 1][n - 1]

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> sumPath(m, vector<int>(n, 1));
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                sumPath[i][j] = sumPath[i - 1][j] + sumPath[i][j - 1];
            }
        }
        
        return sumPath[m - 1][n - 1];
    }
};

//进阶版：若某些位置可能会出现障碍物
//1.定义状态：到达(i, j)的路径和；
//2.递推公式：
//      跳过有障碍的位置
//      F[i][j] = F[i - 1][j] + F[i][j - 1]；
//3.初始值：第一行和第一列均为1
//      第一行中有障碍的位置往右全部无法到达
//      第一列中有障碍的位置往下全部无法到达
//4.返回值：F[m - 1][n - 1]

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> map(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] == 1){
                break;
            }
            map[i][0] = 1;
        }
        
        for(int i = 0; i < n; i++){
            if(obstacleGrid[0][i] == 1){
                break;
            }
            map[0][i] = 1;
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    continue;
                }
                
                map[i][j] = map[i - 1][j] + map[i][j - 1];
            }
        }
        
        return map[m - 1][n - 1];
    }
};
