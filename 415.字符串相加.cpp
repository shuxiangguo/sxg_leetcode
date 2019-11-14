/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (48.07%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    17K
 * Total Submissions: 35.4K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 注意：
 * 
 * 
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
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
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;
        int n1 = 0, n2 = 0, tmp = 0;
        while (i >= 0 || j >= 0) {
            if (i >= 0) n1 = num1[i] - '0';
            else n1 = 0;
            if (j >= 0) n2 = num2[j] - '0';
            else n2 = 0;
            tmp = n1 + n2 + carry;

            carry = tmp / 10;
            res = to_string(tmp % 10) + res;
            i--;
            j--;
        }
        if (carry == 1) {
            return "1" + res;
        } else return res;
    }
};
// @lc code=end

