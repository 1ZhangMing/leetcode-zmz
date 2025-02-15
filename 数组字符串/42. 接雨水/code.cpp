#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int ans=0;
        int len=height.size();
        vector<int> leftmax(len);
        leftmax[0]=height[0];

        for(int i=1;i<len;i++){
            leftmax[i]=max(leftmax[i-1],height[i]);//这是假设水不会往右边流，只会从左边往低处流，这叫问题分解，属于动态规划的思想了
            //cout<<leftmax[i]<<endl;
        }


        vector<int> rightmax(len);
        rightmax[len-1]=height[len-1];
        for(int i=len-2;i>=0;i--){//这里是len-2,因为下面还用到了i+1,注意别越界了
            rightmax[i]=max(rightmax[i+1],height[i]);
           // cout<<rightmax[i]<<endl;
        }


        for(int i=0;i<len;i++){
            ans+=min(leftmax[i],rightmax[i])-height[i];
        }
        return ans;
    }
};

int main(){
Solution solution;
vector<int>a(12);
a={0,1,0,2,1,0,1,3,2,1,2,1};
int res=solution.trap(a);
cout<<res<<endl;
}
