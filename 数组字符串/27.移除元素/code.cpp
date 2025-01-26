#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int inequalnum=0;
        vector<int> temp(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                temp[inequalnum]=nums[i];
                inequalnum++;
            }
        }

        for(int i=0;i<inequalnum;i++){
            nums[i]=temp[i];
        }
        return inequalnum;
    }
};

//甚至没写测试用例，直接过了
int main(){

}
