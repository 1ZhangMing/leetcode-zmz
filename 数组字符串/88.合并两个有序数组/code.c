#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//直接调用过于简单，没啥意义
//class Solution {//直接调用sort
//public:
//    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//
//            //先合并
//            for(int i=0;i<n;i++){
//                nums1[m+i]=nums2[i];
//            }
//            //直接调用sort
//            sort(nums1.begin(),nums1.end());
//    }
//};

class Solution {//使用双指针
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> temp(m+n);

    //定义两个指针，这就叫双指针。
    int p1=0;
    int p2=0;

    for(int i=0;i<m+n;i++){

        //其中一个到头的情况
        if(p1==m){
            temp[i]=nums2[p2];
            p2++;
        }else if(p2==n){
            temp[i]=nums1[p1];
            p1++;
        }

        //都没到头的情况。
        else if(nums1[p1]<nums2[p2]){
            temp[i]=nums1[p1];
            p1++;
        }else{
            temp[i]=nums2[p2];
            p2++;
        }
    }
    
    //挪回来最初的数组
    for(int i=0;i<m+n;i++){
        nums1[i]=temp[i];
    }
    }
};


//交上面的
int main(){
    vector<int> a={1,2,3,4,5,0,0,0,0,0};
    vector<int> b={2,4,6,8,9};
    Solution solution;
    solution.merge(a,5,b,5);
    for(int i=0;i<10;i++){
        cout<<a[i]<<endl;
    }
}
