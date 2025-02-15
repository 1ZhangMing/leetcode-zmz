#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length=nums.size();

       // cout<<length<<endl;
        vector<int> L(length,0),R(length,0);
        vector<int> answer(length);

        L[0]=1;//左边的第一个元素为1 ,这样就可以乘了，不然的话没法×同理R的右边也是1，乘完不影响
        for(int i=1;i<nums.size();i++){
            L[i]=L[i-1]*nums[i-1];//相当于每一个位置的元素都相当于左边的累乘，这叫时空矛盾，把每个位置左边的
            //cout<<L[i]<<endl;
            //存好，这样就不用现算了，实现O（n）,
        }


        //同理处理R,但是这里方向是反向的，先从右边往左×的。
        R[length-1]=1;
        for(int i=length-2;i>=0;i--){
            R[i]=R[i+1]*nums[i+1];
           // cout<<R[i]<<endl;
        }
        for(int i=0;i<length;i++){
            answer[i]=L[i]*R[i];
        }

        return answer;
    }
};
int main(){
Solution solution;
vector<int> a(4);
a={1,2,3,4};
vector<int>result(4);
result=solution.productExceptSelf(a);
for(int i=0 ;i<a.size();i++){
    cout<<result[i]<<endl;
}
}
