/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 *
 * https://leetcode-cn.com/problems/base-7/description/
 *
 * algorithms
 * Easy (46.81%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    7.1K
 * Total Submissions: 15K
 * Testcase Example:  '100'
 *
 * 给定一个整数，将其转化为7进制，并以字符串形式输出。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 100
 * 输出: "202"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: -7
 * 输出: "-10"
 * 
 * 
 * 注意: 输入范围是 [-1e7, 1e7] 。
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public:
    string convertToBase7(int num) {
        vector<string> res;
        if (num == 0) return to_string(0);
        if (num < 0) {
            res.push_back("-");
            num = -1 * num;
        }
        int shang = 0, yushu = 0;
        while (num > 0) {
            yushu = num % 7;
            res.push_back(to_string(yushu));
            num /= 7;
        }

        if (res.at(0) == "-") {
            reverse(res.begin()+1, res.end());
        } else {
            reverse(res.begin(), res.end());
        }
        string result = "";
        for (auto x : res) {
            result += x;
        }
        return result;
    }
};
// @lc code=end

