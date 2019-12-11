//1.定义状态：当第0个位置到第j个位置的字符串合法时，判断从第j个位置到第i个位置的字符串是否合法
//2.递推公式：当j < i && word[j] == true时，判断s.substr(j, i - j)是否在dict中
//3.初始值：word[0] = true;
//4.返回值：word[s.size()];

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> word(n + 1, false);
        word[0] = true;
        
        for(int i = 1; i <= n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(word[j]){
                    string tmp = s.substr(j, i - j);
                    if(dict.find(tmp) != dict.end()){
                        word[i] = true;
                        break;
                    }
                }
            }
        }
        
        return word[n];
    }
};

//改进版
//获取dict中最大的单词长度maxLength，当i- j > maxLength时，则必不可能在词典中
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> word(n + 1, false);
        word[0] = true;
        
        int maxLength = 0;
        for(auto it : dict){
            if(it.size() > maxLength){
                maxLength = it.size();
            }
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = i - 1; j >= 0; j--){
                if(i - j > maxLength){
                    break;
                }
                
                if(word[j]){
                    string tmp = s.substr(j, i - j);
                    if(dict.find(tmp) != dict.end()){
                        word[i] = true;
                        break;
                    }
                }
            }
        }
        
        return word[n];
    }
};
