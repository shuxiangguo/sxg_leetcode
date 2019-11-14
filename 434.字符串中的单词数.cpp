/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode-cn.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (32.61%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 28.8K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 * 
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 * 
 * 示例:
 * 
 * 输入: "Hello, my name is John"
 * 输出: 5
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        bool mark = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ' && mark) {
                cnt++;
                mark = false;
            } else if (s[i] == ' ') mark = true;
        }
        return cnt;
    }
};
// @lc code=end

