#include<iostream>
#include<vector>
using namespace std;

class Solution {//快慢指针解法
public:
    int removeDuplicates(vector<int>& nums) {
        int count=1;//总数
        int tempcount=1;
        for(int i=1;i<nums.size();i++){

         if(nums[i]!=nums[count-1]){//快指针的和慢指针不相同，
             tempcount=1;
             nums[count]=nums[i];
             count++;
         }
         else{//相同
             if(tempcount>=2){
              //  printf("进入了3");
            //    printf("%d",count);
             }
             else{
               //  cout<<"进入了相同但是不超过3"<<endl;
               //  cout<<tempcount<<endl;
                 tempcount++;
                 nums[count]=nums[i];
                 count++;
             }
         }
            cout<<count<<endl;

        }
        return count;
    }
};


class Solution2 {//利用排好序的特点
public:
    int removeDuplicates(vector<int>& nums) {
       int i=0;//新的数组的长度
       for(int num:nums){
           if(i<2||num>nums[i-2]){//前两个肯定都放进去，||右边的意思是，利用了排过序的这一特点，只要前两个和他不同，那么就是变化了
               // 或者说就是没有三个连续相同，两个是可以接受的
               nums[i++]=num;
           }
       }
       return i;

    }
};

int main(){
    Solution solution ;
    vector<int> a(6);
    a={1,1,1,2,2,3};
    int result=solution.removeDuplicates(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
}
