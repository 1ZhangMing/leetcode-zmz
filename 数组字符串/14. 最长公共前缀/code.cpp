#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    string res="";
    for(int i=0;i<strs[0].size();i++){
        char temp;
        temp=strs[0][i];

        int flag=1;
        for(string st:strs){
            if(i<st.size()) {
                if (st[i] != temp) {
                    flag = 0;
                }
            }
            else{
                flag = 0;
            }
        }
        //cout<<temp<<endl;
        if(flag==1){
            res+=temp;
        }
        else{
            return res;
        }

    }
    return res;
    }
};
int main(){
vector<string> a = {"flower", "flow", "flight"};
Solution solution;
string res=solution.longestCommonPrefix(a);
cout<<res<<endl;
}
