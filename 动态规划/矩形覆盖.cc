//1.定义状态：用n个2*1覆盖2*n的方法数
//2.递推公式：取决于最后位置的拜访，竖着摆一个2*1，或者横着摆两个2*1拼成2*2，其他情况均为这两种情况的子集
//      F(n) = F(n - 1) + F(n - 2);
//3.初始值： F[1] = 1; F[2] = 2;
//4.返回值： F[number];

class Solution {
public:
    int rectCover(int number) {
        vector<int> F(number + 1, 0);
        F[1] = 1;
        F[2] = 2;
        
        for(int i = 3; i <= number; i++){
            F[i] = F[i - 1] + F[i - 2];
        }
        
        return F[number];
    }
};

class Solution {
public:
    int rectCover(int number) {
        if(number == 0){
            return 0;
        }
        
        int one = 1;
        int two = 1;
        int ret = 1;
        
        for(int i = 2; i <= number; i++){
            ret = one + two;
            one = two;
            two = ret;
        }
        
        return ret;
    }
};

