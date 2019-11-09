/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (51.01%)
 * Likes:    251
 * Dislikes: 0
 * Total Accepted:    43.5K
 * Total Submissions: 85.1K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int ca = 0;
        char ch = ' ';
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
            int sum = ca;
            sum += (i >= 0) ? a.at(i) - '0' : 0;
            sum += (j >= 0) ? b.at(j) - '0' : 0;
            ch = (sum % 2 == 0) ? '0' : '1';
            res.insert(res.begin(), ch);
            ca = sum / 2;
        }
        if (ca == 1) {
            res.insert(res.begin(), '1');    
        }
        return res;
    }
};
// @lc code=end

