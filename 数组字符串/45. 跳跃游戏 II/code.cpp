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
    int jump2(vector<int>& nums){
        //从最后开始往前走，每次找最大的跳，怎么知道是不是最大的呢，从前往后遍历，能跳直接就停了

        int step=0;
        int position=nums.size()-1;
        while(position>0){//position一跳一跳往前走，不是一步一步挪
            for(int i=0;i<position;i++){//从前开始，一旦能够到，那么直接跳，这就是最远的距离，再往后都没这么远的了
             if(i+nums[i]>=position){
                 step++;
                 position=i;
                 break;
             }
            }
        }
        return step;


    }

};

int main(){
Solution solution;

vector<int>a(5);
a={2,3,1,1,4};
cout<<solution.jump2(a)<<endl;

}
