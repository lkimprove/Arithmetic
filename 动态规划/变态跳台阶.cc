//1.定义状态：跳上第n阶台阶的方法总数 num(n)
//2.递推公式：跳上第n阶台阶的方法总数 = 跳上第n - 1阶台阶后，再跳1台阶 +  跳上第n -2阶台阶后，再2阶台阶 + …… 跳上第0阶台阶后，再跳n阶台阶
//  num(n) = num(n - 1) + num(n - 2) + num(n - 3) …… + num(0); 
//3.初始值：
//  num(0) = 1；
//4.返回结果：num(n)

class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> num(number + 1, 0);
        num[0] = 1;
        
        for(int i = 1; i <= number; i++){
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


//进阶版：当青蛙一次只能跳1阶或者2阶
//1.定义状态：跳上第n阶台阶的方法总数 num(n)
//2.递推公式：跳上第n阶台阶的方法总数 = 跳上第n - 1阶台阶后，再跳1台阶 +  跳上第n -2阶台阶后，再跳2阶台阶
//           因为跳上第3阶台阶后，再跳n - 3台阶这种方法，跳上3阶必须拆分成先跳1阶或者2阶，与前面重复，所以不能算进来
//  num(n) = num(n - 1) + num(n - 2)
//3.初始值：
//  num(0) = 1；num(1) = 1；
//4.返回结果：num(n) 

class Solution {
public:
    int jumpFloor(int number){
        vector<int> num(number + 1, 0);
        num[0] = 1;
        num[1] = 1;
        
        for(int i = 2; i <= number; i++){
            int j = 1;
            while(j != 3){
                num[i] += num[i - j];
                j++;
            }
        }
        
        return num[number];
    }
};

//改进版：只需保留三个值即可
class Solution {
public:
    int jumpFloor(int number) {
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














