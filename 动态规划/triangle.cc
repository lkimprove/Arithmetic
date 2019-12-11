//1.定义状态：从(0, 0)到达(i, j)的最小路径和
//2.递推公式：
//    F[i][0] = F[i - 1][0]
//    F[i][i] = F[i - 1][i - 1]
//    F[i][j] = min(F[i - 1][j - 1], F[i - 1][j])
//3.初始值: F[0][0] = triangle[0][0]      
//4.返回值：最后一行中的最大值

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        
        for(int i = 1; i < m; i++){
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
            
            for(int j = 1; j < i; j++){
                int tmp = min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                triangle[i][j] += tmp;
            }
        }
        
        int ret = triangle[m - 1][0];
        for(int i = 1; i < m; i++){
            if(ret > triangle[m - 1][i]){
                ret = triangle[m - 1][i];
            }
        }
        
        return ret;
    }
};

//改进版
//1.定义状态：从(i, j)到(0, 0)的最小路径和
//2.递归公式：F[i][j] = min(F[i + 1][j], F[i + 1][j + 1])
//3.初始值：最后一行不变
//4.返回值：F[0][0]

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        
        for(int i = m - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        
        return triangle[0][0];
    }
};

//易错点：只保留每一步的最小值，忽略其他路径，造成最终结果错误
//局部最小不等于全局最小

