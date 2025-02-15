#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int i=0;//初始位置,i表示的就是开始的位置，cnt表示相对位移，往后移动的距离
        int n=gas.size();
        while(i<n){
            int cnt=0;//表示移动的距离，如果移动了n，那么就说明回到了原点了，这比坐标值法好，不用判断是不是开始的时候
            int sumGas=0;
            int sumCost=0;
            while(cnt<n){
                int j=(i+cnt)%n;//当前的一步
                sumGas=sumGas+gas[j];
                sumCost=sumCost+cost[j];


                if(sumCost>sumGas){//保留崩殂的位置，这里就是不行的地方，不要再加了
                    break;
                }
            //如果上一步没break，那么才进行++，这才是真正的往前走了一步
            cnt++;
            }
            if(cnt==n){
                return i;
            }
            else{
                i= i+cnt+1;//得到从x到y崩殂了，那么就前往y+1，这里y就是i＋cnt

                //背后的原理就是，你从x到y不行，那么你从x到y之间的任意一个地方开始走，其起步都是0，还不如你这样从x开始，
                // 起码会保证在你这个位置的油量不是0，比你这个情况好一点，
            }

        }
        return -1;
    }
};
int main(){

Solution solution;
vector<int> a(5);
a={1,2,3,4,5};
vector<int> b(5);
b={3,4,5,1,2};

int resu=solution.canCompleteCircuit(a,b);
cout<<resu<<endl;

}
