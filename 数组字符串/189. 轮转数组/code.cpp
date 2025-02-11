#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {//例如12345，3
     k=k%(nums.size());//先是模，不然没有意义
     reverse(nums,0,nums.size()-1);//首先整个反转54321
     reverse(nums,0,k-1);//然后从第k-1个开始反转回来，这是34521
     reverse(nums,k,nums.size()-1);//34512

    }

    void reverse(vector<int>& nums,int start,int end){//从start，到end，全部反转的函数
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }

    }
};

int main(){
vector<int>a (5);
a={1,2,3,4,5};
Solution solution;
solution.rotate(a,3);
for(int i=0;i<5;i++){
    cout<<a[i]<<endl;
}
}
