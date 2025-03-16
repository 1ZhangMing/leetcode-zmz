#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res="";
        int index=s.size()-1;
        //1去除最后的空格
        while(index>=0 && s[index]==' '){//防止数组越界
            index--;
        }
        while(index>=0){
            cout<<index<<endl;
            int index2=index;
            if(s[index]!=' '){//不是空格的情况

                while(index2>=0 && s[index2] != ' '){
                    index2--;
                }
                int length=index-index2;
                for (int i=1;i<=length;i++){
                    res+=s[index2+i];
                }
                index=index2;
            }
            else if(s[index]==' '){
                while(index>=0 && s[index]==' '){//防止数组越界
                    index--;
                }
                res+=' ';
            }

        }
        //3去除开头的空格
        if(s[0]==' '){
            res.pop_back();
        }
        return res;

    }
};

int main(){
string a = "a good   example";
Solution solution;
string res=solution.reverseWords(a);
cout<<res<<endl;
}
