#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;//用来计数
        vector<int> temp(nums.size());//暂存数组，这里初始化记得规范
        temp[0]=nums[0];
        for(int i=1;i<nums.size();i++){//这里是因为题目说了知道一个元素，
          /*
          提示：
          
          1 <= nums.length <= 3 * 104
          -104 <= nums[i] <= 104
          nums 已按 非严格递增 排列
          */
            if(nums[i]!=temp[count-1]){
                count++;
                temp[count-1]=nums[i];
            }
        }
        for(int i=0;i<temp.size();i++){
            nums[i]=temp[i];
        }
        return count;

    }
};


int main(){
vector<int>a={1,1,2,2,3};
Solution solution;
int result=solution.removeDuplicates(a);
cout<<result<<endl;
for(int i=0;i<a.size();i++){
    cout<<a[i]<<endl;
}
}
