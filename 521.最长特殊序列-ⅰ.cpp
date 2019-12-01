/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 *
 * https://leetcode-cn.com/problems/longest-uncommon-subsequence-i/description/
 *
 * algorithms
 * Easy (64.39%)
 * Likes:    38
 * Dislikes: 0
 * Total Accepted:    7.3K
 * Total Submissions: 11.3K
 * Testcase Example:  '"aba"\n"cdc"'
 *
 * 给定两个字符串，你需要从这两个字符串中找出最长的特殊序列。最长特殊序列定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。
 * 
 * 子序列可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。
 * 
 * 输入为两个字符串，输出最长特殊序列的长度。如果不存在，则返回 -1。
 * 
 * 示例 :
 * 
 * 输入: "aba", "cdc"
 * 输出: 3
 * 解析: 最长特殊序列可为 "aba" (或 "cdc")
 * 
 * 
 * 说明:
 * 
 * 
 * 两个字符串长度均小于100。
 * 字符串中的字符仅含有 'a'~'z'。
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
    int findLUSlength(string a, string b) {
        if (a == b) return -1;
        return a.size() > b.size() ? a.size() : b.size();
    }
};
// @lc code=end

