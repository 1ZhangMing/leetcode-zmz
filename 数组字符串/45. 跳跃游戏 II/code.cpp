#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int step=0;
        int maxPosition=0;
        int end=0;
        for(int i=0;i<nums.size()-1;i++){//最后一个不必跳
            maxPosition=max(maxPosition,i+nums[i]);//取最远距离为从这一步到下一步之间
            //任意一跳的最远位置，也就是不一定在最后跳，可以在中间任何位置跳。

            if(i==end){//一开始end为0。
                end=maxPosition;
                step++;

            }
        }

        return step;

    }
};
int main(){
Solution solution;

vector<int>a(5);
a={2,3,1,1,4};
cout<<solution.jump(a)<<endl;

}
