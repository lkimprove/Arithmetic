//1.定义状态：以i位结尾的子数组的最大值
//2.递推公式：F[i] = max(F[i - 1] + A[i], A[i])
//3.初始值：F[0] = A[0];
//4.返回值：最大的那个F[i]

class Solution {
public:
    int maxSubArray(int A[], int n) {
        vector<int> maxArry(n, 0);
        maxArry[0] = A[0];
        
        int ret = maxArry[0];
        for(int i = 1; i < n; i++){
            maxArry[i] = max(maxArry[i - 1] + A[i], A[i]);
            if(ret < maxArry[i]){
                ret = maxArry[i];
            }
        }
        
        return ret;
    }
};

//改进版
//递推公式只涉及以i - 1结尾的子数组的最大值
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = A[0], sumMax = A[0];
        
        for(int i = 1; i < n; i++){
            sum = max(sum + A[i], A[i]);
            sumMax = max(sum, sumMax);
        }
        
        return sumMax;
    }
};
