#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
private:
    unordered_map<char,int> mapaa={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
    };
public:
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.size()-1;i++){
            if(mapaa[s[i]]<mapaa[s[i+1]]){
                ans-=mapaa[s[i]];
            }else{
                ans+=mapaa[s[i]];
            }
        }
        ans+=mapaa[s[s.size()-1]];
        return ans;
    }
};

int main(){
    Solution solution;
    string a ="III";
    cout<<solution.romanToInt(a)<<endl;
}
