#include<iostream>
#include<vector>
using namespace std;

const pair<int,string> valueSymbols[]={//这东西得定义在SOlution之前啊
        //注意题目描述中的范围，注定了最大值3999，我们做到M表示1000就够了
        {1000,"M"},
        {900,"CM"},
        {500,"D"},
        {400,"CD"},
        {100,"C"},
        {90,"XC"},
        {50,"L"},
        {40,"XL"},
        {10,"X"},
        {9,"IX"},
        {5,"V"},
        {4,"IV"},
        {1,"I"},
};
class Solution {
public:
    string intToRoman(int num) {
        string roman;
        for(const auto&[value,symbol]:valueSymbols){//对于每一个pair
            while(num>=value){//注意这里有一个正好等于的情况，对应下面的if，
                                //这时候就是正好减完的情况，然后就可以break了
                num-=value;
                roman+=symbol;
            }
            if(num==0){
                break;
            }
        }
        return roman;
    }
};
int main(){
Solution solution;

int numexample=3749;
string roman =solution.intToRoman(numexample);
cout<<"输出试一试"<<roman<<endl;

}
