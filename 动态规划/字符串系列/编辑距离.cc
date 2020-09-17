//给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
//你可以对一个单词进行如下三种操作：
//插入一个字符
//删除一个字符
//替换一个字符

//输入: word1 = “horse”, word2 = “ros”
//  输出: 3
//  解释:
//  horse -> rorse (将’h’ 替换为 ‘r’)
//  rorse -> rose (删除 ‘r’) rose -> ros (删除 ‘e’)

 //记 s 中以下标 i − 1 结尾的子串，与 t 中以下标 j − 1 结尾的子串的最小距离为 dp[i][j]，则
 //cur1 = min(dp[i - 1][j], dp[i][j - 1]) + 1;
 //cur2 = 
 //1.dp[i - 1][j - 1]; word1[i - 1] = word2[j - 1];
 //2.dp[i - 1][j - 1] + 1; word[i - 1] != word2[j-  1];
 
 
 class Solution {
public:
    /**
     * 
     * @param word1 string字符串 
     * @param word2 string字符串 
     * @return int整型
     */
    int minDistance(string word1, string word2) {
        // write code here
        int s1 = word1.size(), s2 = word2.size();
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
        
        //初始化
        for(int i = 1; i <= s1; i++){
            dp[i][0] = i;
        }
        for(int j = 1; j <= s2; j++){
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= s1; i++){
            for(int j = 1; j <= s2; j++){
                int cur1 = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                
                int cur2 = 0;
                if(word1[i - 1] == word2[j - 1]){
                    cur2 = dp[i - 1][j - 1];
                }
                else{
                    cur2 = dp[i - 1][j - 1] + 1;
                }
                
                dp[i][j] = min(cur1, cur2);
            }
        }
        
        return dp[s1][s2];
    }
};
