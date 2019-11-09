/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (31.26%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    46.7K
 * Total Submissions: 149.4K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int endIdx = s.size() - 1;
        while (endIdx >= 0 && s.at(endIdx) == ' ') {
            endIdx--;
        }
        if (endIdx < 0) return 0;
        int start = endIdx;
        while (start >= 0 && s.at(start) != ' ') {
            start--;
        }
        return endIdx - start;
    }
};
// @lc code=end

