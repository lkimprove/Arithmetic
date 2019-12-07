//1.定义状态：跳上第n阶台阶的方法总数 num(n)
//2.递推公式：跳上第n阶台阶的方法总数 = 跳上第1阶台阶后，再跳n - 1台阶 +  跳上第2阶台阶后，再n - 2阶台阶 + …… 跳上第0阶台阶后，再跳上n阶台阶
//  num(n) = num(n - 1) + num(n - 2) + num(n - 3) …… + num(0); 
//3.初始值：
//  num(0) = 1；num(1) = 1；
//4.返回结果：num(n)

class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> num(number + 1, 0);
        num[0] = 1;
        num[1] = 1;
        
        for(int i = 2; i <= number; i++){
            for(int j = i - 1; j >= 0; j--){
                num[i] += num[j];
            }
        }
        
        return num[number];
    }
};

//改进版
//num(n) = num(n - 1) + num(n - 2) + num(n - 3) …… + num(0); 
//num(n - 1) = num(n - 2) + num(n - 3) …… + num(0); 
//num(n) = 2 * num(n - 1);
//num(1) = 1;
//num(2) = 2 * 1 = 2;
//num(3) = 2 * 2 = 4;
//num(n) = 2 ^ (n - 1);
//ps：
//  排列思想：除最后一阶台阶必须跳上去外，其他的所有台阶均有两种可能，跳或不跳，所以 num(2) = 2 ^ (n - 1)

class Solution {
public:
    int jumpFloorII(int number) {
        return 1 << (number - 1);
    }
};

