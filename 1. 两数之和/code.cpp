#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//通过哈希映射，来保存每一个数对应的一对另一个数，每次只需查找这个map（时间复杂度O（1））就行了，而不用遍历整个数组。

class Solution{
public:

    /*
    class Solution{
    public:};是leetcode上提交代码必须的格式
     * */

    //传入两个参数一个是vector类型的地址，其实就是数组，另一个是数字，返回vector类型的返回值，
    vector<int> twoSum(vector<int>& nums,int target){
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            int different=target-nums[i];
            if(map.find(different)!=map.end()){
             return {map[different],i};//返回对应位置
            }
            //每一个都要存入map中，使用i为索引（当前位置），返回也是返回其位置
            map[nums[i]]=i;
        }
        return {};
    }
};


//提交上面的部分
int main (){
    vector<int> numstest={1,5,6};
    int target_test=7;
    Solution solution;
    vector<int> result=solution.twoSum(numstest,target_test);
    cout<<result[0]<<","<<result[1]<<endl;

}
