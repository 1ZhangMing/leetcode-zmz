#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    unordered_map <int,int> counts;//存储每个元素对应的个数
    int majority=0;
    int count=0;
    for(int num:nums){//遍历所有的元素。
        counts[num]++;
        if(counts[num]>count){//打擂台
            count=counts[num];
            majority=num;
        }
    }
    return majority;
    }
};

int main(){
    vector<int> a(5);
    a={1,1,2,2,2};
    Solution solution;
    int result=solution.majorityElement(a);
    cout<<result<<endl;
}
