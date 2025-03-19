#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        //1先换成z矩阵
        //行数肯定是numrows，列数呢，看看多少个周期，每个周期R+R-2总共2R-2，然后每个周期R-1列
        //总共每个周期为T，总共(n+t-1)/t其实就是n/t的上取整的表达方式


        int length=s.length();
        int R=numRows;
        if(R==1||R>=length){
            return s;
        }

        int t=2*R-2;
        int n=(length+t-1)/t;//总共n个周期
        int col=n*(R-1);
        //cout<<n<<endl;
        //cout<<col<<endl;

        //创建矩阵
        vector<string>mat(R,string(col,0));//这里和创建向量不一样，这里是矩阵，二维的，
        //也是会用到二维的向量的。所以总共R行，每行col个,并且都是0



        for(int i=0,x=0,y=0;i<length;i++){
            mat[x][y]=s[i];
            //这里二维矩阵的写法很有意思，就是先取出第一个维度的向量，然后再从中再次取值
            //上面也是这么一个写法，就是先定义第一个维度就是行，然后其中每个的取值都是string（col,0）
            //再定义每一行的具体内容，其中的取值就是col个0
            if(i%t<R-1){//最后这个位置可不能在往下走了，停了
                x++;//向下移动
            }
            else{
                x--;//向上移动，
                y++;//向右移动
            }
        }


        string res;
        for(auto &row:mat){//拿出mat里面的所有元素，其实就是拿出来所有的行
            //起名为row,变量类型自动确定
            for(char ch:row){//拿出来row里面的所有ch
                if(ch){
                    res+=ch;
                }
            }
        }
        return res;

        //2输出看看

    }
};

int main(){
    Solution solution;
    string s = "PAYPALISHIRING";
    string res=solution.convert(s,3);
    cout<<res<<endl;

}
