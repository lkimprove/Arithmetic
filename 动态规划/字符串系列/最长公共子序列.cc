问题描述：给出两个字符串，找到最长公共子序列(LCS), 输出LCS。
输入: s = “ABCD”, t = “EABDF”
输出: ABD


//不同于子串，子序列的定义更加宽松。对于字符串 s ss, 子串要求从 s ss 中顺序取出，并且严格相邻；而子序列则只要求顺序取出，而不一定相邻(可以不连续)
//倘若记 s 中以下标 i − 1  结尾的子串，与 t 中以下标 j − 1 结尾的子串最长公共子串的长度为 dp[i][j] ，则状态转移方程为
//dp[i][j] = 
//  dp[i - 1][j - 1] + 1; s[i - 1] == t[j-  1]
//  max(dp[i - 1][j], dp[i][j - 1]); otherwise

class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        // write code here
        int n = s1.size(), m = s2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1]== s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        int maxlen = dp[n][m];
        if(maxlen == 0){
            return "-1";
        }
        
        string ret;
        int i = 1, j = 1;
        while(maxlen > 0 && i <= n && j <= m){
            if(dp[i][j] == dp[i - 1][j]){
                i++;
            }
            else if(dp[i][j] == dp[i][j - 1]){
                j++;
            }
            else{
                ret.push_back(s1[i - 1]);
                i++;
                j++;
                maxlen--;
            }
        }
        
        return ret;
    }
};
