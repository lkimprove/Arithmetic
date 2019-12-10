class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        
        for(int i = 1; i < m; i++){
            //每一行的第一个和最后一个由上行的一个值决定
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
            
            //其余值由上行的两个值决定
            for(int j = 1; j < i; j++){
                int tmp = min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                triangle[i][j] += tmp;
            }
        }
        
        //寻找最大值
        int ret = INT_MAX;
        for(int i = 0; i <= m - 1; i++){
            if(ret > triangle[m - 1][i]){
                ret = triangle[m - 1][i];
            }
        }
        
        return ret;
        
    }
};

//改进版
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        
        //后往前遍历
        for(int i = m - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                int tmp = min(triangle[i + 1][j], triangle[i + 1][j + 1]);
                triangle[i][j] += tmp;
            }
        }
        
        return triangle[0][0];
    }
};
