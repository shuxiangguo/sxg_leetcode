/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> m;
        unordered_map<string,int> used;
        vector<string> vs;
        string s;
        int pos;
        int i=0;

        while(pos!=-1)//读取str中的单词
        {
            pos=str.find_first_of(' ',i);//相当于返回每个空格的索引值,如果找不到空格则-1
            string temp=str.substr(i,pos-i);//截取单词
            vs.push_back(temp);//插入单词元素
            i=pos+1;//相当于每个单词的首位索引值
        }


        if(vs.size()!=pattern.size()) return false;
        
        for(int i = 0;i<pattern.size();i++){//遍历左边数组
            s = vs[i];//依次赋值单词字符串
            if(m.count(pattern[i])==0) //如果左边(pattern)数组出现新字母时,执行
                if(used[s]) return false;//因为每个新字母对应一个新单词,不能新字母对应旧字符串
                                        //所以出现新字母时,要保证单词也是新的,如果是已经出现过的字符串则返回false
                else{
                    m[pattern[i]] = s;  //匹配键值对
                    used[s]++;         //相当于标记某个单词已经出现过了
                }
            else if(s!=m[pattern[i]]) return false;//判断str中第i个的字符串是否与映射表中第i位所对应的字符串相等
        }
        return true;
    }
};
// @lc code=end