//n张卡片，n个盒子，每个盒子放一张卡片，一共有多少种放法

#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int>& book, vector<int>& box, int index, int n){
    //终止条件，当所有卡片都已经放入盒子里
    if(index == n + 1){
        for(int i = 1; i <=n; i++){
            cout << box[i]  << " ";
        } 

        cout << endl;
        return;
    }
    
    for(int i = 1; i <= n; i++){
        //当该张卡片没有被放入某个盒子
        if(book[i] == 0){
            box[index] = i;
            book[i] = 1;    //将该卡片置为1，表示该卡片已经使用

            DFS(book, box, index + 1, n);   //给下一个盒子选择卡片放入
            
            book[i] = 0;    //回收该卡片，返回上一步
        }
    }
}

//测试
void Test(){
    int n;
    cin >> n;

    vector<int> book(n + 1, 0);
    vector<int> box(n + 1, 0);
    
    DFS(book, box, 1, n);
}


int main(){
    Test();

    return 0;
}
