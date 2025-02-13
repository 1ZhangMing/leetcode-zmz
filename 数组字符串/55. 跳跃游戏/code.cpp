#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        int most=0;//最远的能到达的位置，每一经过一个元素都要更新这个，看看能不能最终大于len
        for(int i=0;i<len;i++){
            if(most<i){//如果没到这一步
                return false;
            }
            //如果到了这一步。
            //使用i+nums[i]首先与most相比，看看能不能更新,能的话就是表示从这一步可以跳跃
            //到更远的距离
            if(most<i+nums[i]){
                most=i+nums[i];
            }

            //判断成功的条件
            if(most>=len-1){
                return true;
            }

        }
        return false;

    }
};
int main(){
Solution solution;
vector<int> a(5);
a={4,2,1,0,4};
cout<<solution.canJump(a)<<endl;

}
