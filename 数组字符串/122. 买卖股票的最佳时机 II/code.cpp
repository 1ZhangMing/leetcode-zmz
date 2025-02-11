
#include<iostream>
#include<vector>
using namespace std;
//终于碰到个简单题，简单题搞啥动态规划啊，99%
//因为交易次数不受限，如果可以把所有的上坡全部收集到，一定是利益最大化的
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                ans+=prices[i]-prices[i-1];
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> a (5);
    a={1,2,0,4,5};
    cout<<solution.maxProfit(a)<<endl;

}
