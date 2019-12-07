//1.定义状态：斐波那契数列第n项的值Fib(n);
//2.确定递推公式：Fib(n) = Fib(n - 1) + Fib(n - 2);
//3.确定初始值：Fib(0) = 0; Fib(1) = 1;
//4.确定返回值：Fib(n);

class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0){
            return 0;
        }
        
        vector<int> Fib(n + 1, 0);
        Fib[1] = 1;
        
        for(int i = 2; i <= n; i++){
            Fib[i] = Fib[i - 1] + Fib[i - 2];
        }
        
        return  Fib[n];
    }
};

//改进版：
//  当求第n项时，只需知道第n - 1项和第n - 2项的值即可，所以只需保存三个值即可
class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0){
            return 0;
        }
        
        int one = 1;
        int two = 1;
        int ret = 1;
        
        for(int i = 3; i <= n; i++){
            ret = one + two;
            one = two;
            two = ret;
        }
        
        return ret;
    }
};









