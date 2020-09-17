//问题描述：给出两个字符串，找到最长公共子串，并返回其长度。
//  输入: s = “ABCD”, t = “EABDF”
//  输出: 2
//  解释: s 和 t 的最长公共子串为 “AB”
 
//倘若记 s 中以下标 i − 1  结尾的子串，与 t 中以下标 j − 1 结尾的子串最长公共子串的长度为 dp[i][j] ，则状态转移方程为
// dp[i][j]:
//  1.dp[i - 1][j - 1] + 1; s[i] == t[j]
//  2.0;  otherwise

class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int s1 = str1.size(), s2 = str2.size();
        
        int maxlen = 0, sign = 0;
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
        for(int i = 1; i <= s1; i++){
            for(int j = 1; j <= s2; j++){
                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    
                    if(maxlen < dp[i][j]){
                        maxlen = dp[i][j];
                        sign = i - maxlen;
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        
        if(maxlen == 0){
            return "-1";
        }
        
        string ret;
        for(int i = 0; i < maxlen; i++){
            ret.push_back(str1[sign++]);
        }
        
        return ret;
    }
};
