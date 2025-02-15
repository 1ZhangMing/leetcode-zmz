#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
    int count=0;
    int length=ratings.size();
    count+=length;

    vector<int> L(length,0);
    vector<int> R(length,0);

    L[0]=0;
    for(int i=1;i<length;i++){
     if(ratings[i]>ratings[i-1]){
         L[i]=L[i-1]+1;//可以是0，1，2，3，4.。。。没有数量的限制，可以是比左边大，但是没有限制大小说只能是1
        // cout<<i<<endl;
     }
    }
//    for(int i=0;i<length;i++){
//        cout<<L[i]<<endl;
//    }


    R[length-1]=0;
    for(int i=length-1;i>=1;i--){
        if(ratings[i]<ratings[i-1]){
            R[i-1]=R[i]+1;
         //   cout<<i<<endl;
        }
    }

    vector<int> answer(length,0);
    for(int i=0;i<length;i++){
     answer[i]=max(L[i],R[i]);//不能是直接相加，那么可能比左边大和右边大，但是两边都是0，那么你只能是1而不是1+1等于2，因为
    }

    for(int i=0;i<length;i++){
    if(answer[i]>0){
       count+=answer[i];
    }
    }
    return count;
    }

};
int main(){
    Solution solution;
    vector<int> a(7);
    a={1,2,87,87,87,2,1};
    int aa=solution.candy(a);
    cout<<aa<<endl;
}
