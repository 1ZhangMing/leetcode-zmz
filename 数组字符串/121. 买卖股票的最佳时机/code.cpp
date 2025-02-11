#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minp=1e9;//记录下最小值
        int maxProf=0;//最大值随时比较
        for(int price:prices){//对于每一个时间点而言，和前面的进行比较，看看是不是能刷新最大值的记录，而不是暴力O（n2）的办法解决
            maxProf=max(maxProf,price-minp);
            minp=min(price,minp);
        }
        return maxProf;

    }
};
int main(){
Solution solution;
vector<int> a (5);
a={1,2,0,4,5};
cout<<solution.maxProfit(a)<<endl;

}
