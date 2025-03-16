#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int index=s.size()-1;//字符串的长度，说白了C++里面的字符串就可以按数组一样处理
        //由于从0开始，所以最后减一

        //1删去后面的空白，看第二个测试用例
        while(s[index]==' '){
            index--;
        }

        int count=0;
        while(  index>=0&&s[index]!=' ')//防止左边溢出,还有为了防止数组越界，所以将s[index]放在右边
        {
            count++;
            index--;
        }
        return count;
    }
};
int main(){
   string  s = "   fly me   to   the moon  ";
   Solution solution;
   int res=solution.lengthOfLastWord(s);
   cout<<res<<endl;

}
