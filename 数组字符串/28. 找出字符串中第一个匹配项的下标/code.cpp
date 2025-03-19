#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
    int lenH=haystack.length();
    int lenN=needle.length();
    if(lenN>lenH){//刁民
        return -1;
    }
    for(int i=0;i<lenH-lenN+1;i++) {//对于每一个position来说，都要进行遍历,这里+1是因为可能有相同的存在
        int flag=1;
        for(int j=0;j<lenN;j++){
            if(needle[j]!=haystack[i+j]){
                flag=0;
            }
        }
        if(flag==1){//说明每一个都对上了
            return i;
        }
    }
    return -1;
    }
};

int main(){
     string haystack = "sadbutsad";
     string needle = "sad";
     Solution solution;
     int res=solution.strStr(haystack,needle);
     cout<<res<<endl;
}
