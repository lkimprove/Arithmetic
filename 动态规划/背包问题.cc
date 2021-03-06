class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int n = A.size();
        
        vector<vector<int>> F(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                //如果当前物品大于背包的容量，则放不下
                if(A[i - 1] > j){
                    F[i][j] = F[i - 1][j];
                }
                //当背包可以放下当前物品时，则需要判断是否放入当前物品
                //F[i][j] = max(F[i - 1][j], F[i- 1][j - A[i - 1]] + V[i - 1])
                //F[i - 1][j - A[i- 1]] + V[i - 1]包含两种情况：
                //1.可以直接放入当前物品2.需要移除某个物品后放入当前物品
                else{
                    F[i][j] = max(F[i - 1][j], F[i - 1][j - A[i - 1]] + V[i - 1]);
                }
            }
        }
        
        return F[n][m];
    }
};


//改进版
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int n = A.size();
        
        vector<int> F(m + 1, 0);
        
        //节省空间复杂度的做法
        //因为计算时只需要上一行的数据，所以只需要一行数据即可
        //计算当前位置数据时，需要上一行往前的位置，所以需要从后往前计算
        for(int i = 0; i < n; i++){
            for(int j = m; j > 0; j--){
                if(A[i] > j){
                    continue;
                }
                else{
                    F[j] = max(F[j], F[j - A[i]] + V[i]);
                }
            }
        }
        
        return F[m];
    }
};
