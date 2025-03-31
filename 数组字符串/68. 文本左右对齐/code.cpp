#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string temp;
        for(int i=0;i<words.size();i++){
            //cout<<i<<endl;
            //第一步确定能放几个进去
            temp="";
            int len=-1;//刨去最开始的空格
                int j=i;
            while(len<=maxWidth&&j<words.size()){
                //cout<<"len:"<<len<<"j:"<<j<<endl;

                len+=words[j].length()+1;
                j++;
                if(len>maxWidth){

                    j--;
                    len-=words[j].length()+1;
                    //cout<<"break:len,j"<<len<<" "<<j<<endl;
                    break;
                }
                if(j==words.size()){

                    break;
                }
            }
            if(j==words.size()){
                //cout<<"i:"<<i<<endl;
                while(i<j){
                    if(i!=j-1){
                        temp+=words[i]+" ";
                    }else{
                        temp+=words[i];
                    }

                    i++;
                }
                while(temp.length()<maxWidth){
                    temp+=" ";
                }
            }else{
                string temp2;
                int len2=j-i;
                while(i<j){
                    temp2+=words[i];
                    i++;
                }
                i=i-len2;
                int block;
                block=maxWidth-temp2.length();
                int count=0;
                int pos=0;
                //cout<<len2-1<<endl;
                if((len2-1)==0){
                    len2++;
                }
                int num[len2-1];
                memset(num,0,sizeof num);
                while(block>0){
                    pos=count%(len2-1);
                    num[pos]+=1;

                    count++;
                    block--;
                }
//                for(int h=0;h<len2-1;h++){
//                    //cout<<"num"<<num[h]<<endl;
//                }
                int start=i;
                while(i<j){

                    temp+=words[i];
                    if(i<j-1){
                        for(int k=0;k<num[i-start];k++){
                            temp+=" ";
                        }
                        //cout<<"i,j"<<i<<" "<<j<<endl;
                        //cout<<num[i-start]<<endl;
                    }
                    i++;

                }
                while(temp.length()<maxWidth){
                    temp+=" ";
                }
                //cout<<"temp"<<temp<<endl;
            }

            i--;
            ans.push_back(temp);
        }
        return ans;
    }
};
int main(){
    vector<string>a ;
    a= {"What","must","be","acknowledgment","shall","be"};
    int maxwidth=16;
    Solution solution;
    vector<string> ans;
    ans=solution.fullJustify(a,maxwidth);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
