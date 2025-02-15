#include<iostream>
#include<vector>//动态数组
#include<cstdlib>//rand和srand
#include<ctime>//time函数
#include<unordered_map>
using namespace std;

//变长数组加上哈希表
//变长数组负责O（1）的插入和删除
//哈希表负责O（1）查找
class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));//用时间来初始化随机种子
    }

    bool insert(int val) {
        if(indices.count(val)){//通过哈希表来O（1）判断是不是存在这个数
            //这里是通过传入键k来查找数量的
            return false;
        }
        int index=nums.size();//大小就是最末尾的元素的下标+ 1，就是新的元素的位置。
        nums.emplace_back(val);//这就是动态数组插入新元素的位置。
        indices[val]=index;//根据这个取值保存其位置。
        return true;
    }

    bool remove(int val) {
        if(!indices.count(val)){//O(1)的查找是否存在，如果用数组只能O（n）了
            //不存在的话
            return false;
        }
        //思路就是把最后一个元素挪到这个元素的位置，然后最后一个元素删掉，然后hashmap中也删掉
        int index=indices[val];//得到其在数组中的位置。
        int last=nums.back();//获取最后一个元素的方法，原来back是最后一个元素的意思啊
        nums[index]=last;//直接搬过来，相当于删除这个元素了
        indices[last]=index;//hashmap的最后一个元素的位置也需要更新，查找位置依旧O(1)。
        nums.pop_back();//依旧back是最后一个元素
        indices.erase(val);
        return true;
    }

    int getRandom() {
        int rdindex=rand()%nums.size();
        return nums[rdindex];
    }
private:
    vector<int>nums;
    unordered_map<int,int> indices;


};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

