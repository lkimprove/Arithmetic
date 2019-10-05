//LeetCode 图像渲染

static int newPoint[4][2] = { {0, -1}, {0 ,1}, {1, 0}, {-1, 0} };
class Solution {
public:
    void DFS(vector<vector<int>>& image, vector<vector<int>>& book, int row, int col, int sr, int sc, int oldColor, int newColor){
        //渲染当前颜色并标记
        image[sr][sc] = newColor;
        book[sr][sc] = 1;   //若不标记，当出现newColor == oldColor时，会出现死循环
        
        //获取新的坐标
        for(int i = 0; i < 4; i++){
            int newx = sr + newPoint[i][0];
            int newy = sc + newPoint[i][1];
            
            //判断是否越界
            if(newx >= row || newx < 0 || newy >= col || newy < 0){
                continue;
            }
            
            //判断新的坐标是否需要渲染
            if(image[newx][newy] == oldColor && book[newx][newy] == 0){
                DFS(image, book, row, col, newx, newy, oldColor, newColor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //判空
        if(image.empty()){
            return image;
        }
        
        //获取行和列和要被渲染的颜色
        int row = image.size();
        int col = image[0].size();
        int oldColor = image[sr][sc];
        
        //创建标记
        vector<vector<int>> book(row, vector<int>(col, 0));
        
        DFS(image, book, row, col, sr, sc, oldColor, newColor);
        
        return image;
    }
};
