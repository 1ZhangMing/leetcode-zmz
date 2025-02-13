#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
    int H=0;
    int len=citations.size();
    for(int i=1;i<len+1;i++){//h的最大值为len
        int counth=0;//从0开始试h
        for(int j=0;j<len;j++){
            if(citations[j]>=i){
                counth++;
            }
        }
        if(counth>=i){
            H=i;
        }
    }
    return H;
    }

    int hIndex2(vector<int>& citations) {
        int H=0;
        int i=citations.size()-1;
        sort(citations.begin(),citations.end());
        while(i>=0&&citations[i]>H){//为什么是>H呢，因为这是跳之前，得明确大于了才会继续往前看，等于了的话就不用看了
         H++;
         i--;//注意这里最终有可能是i小于0，但是这种情况下你仍旧while(citations[i]>H&&i>=0)那么就会报一个
         // 数组越界的错Line 1122: Char 34: runtime error: addition of unsigned offset to 0x5020000001f0 overflowed to 0x5020000001ec (stl_vector.h)
            //SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/lib/gcc/x86_64-linux-gnu/14/../../../../include/c++/14/bits/stl_vector.h:1131:34class


            //“ addition of unsigned offset to 0x5020000001f0 overflowed to 0x5020000001ec”又是地址又是溢出的，
            //可不就是数组越界么
        }
        return H;
    }
};

int main(){
Solution solution;
vector<int>a(5);
a={1,3,1};
cout<<solution.hIndex2(a)<<endl;

}
