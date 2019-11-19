/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode-cn.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (43.65%)
 * Likes:    123
 * Dislikes: 0
 * Total Accepted:    10.6K
 * Total Submissions: 24.1K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "abab"
 * 
 * 输出: True
 * 
 * 解释: 可由子字符串 "ab" 重复两次构成。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "aba"
 * 
 * 输出: False
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: "abcabcabcabc"
 * 
 * 输出: True
 * 
 * 解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size(), i = 0, t = 0;
        for (t = 1; t <= len / 2; t++) {
            if (len % t)continue; // 有余数，一定不是周期串
            for (i = t; i < len && s[i%t] == s[i]; i++) {
            }
            if (i == len) return true;
        }
        return false;
    }
};
// @lc code=end

