/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 *
 * https://leetcode-cn.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (59.34%)
 * Likes:    93
 * Dislikes: 0
 * Total Accepted:    16.3K
 * Total Submissions: 27.5K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * s = "abcd"
 * t = "abcde"
 * 
 * 输出：
 * e
 * 
 * 解释：
 * 'e' 是那个被添加的字母。
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
    char findTheDifference(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        int i;
        for (i = 0; i < s.size(); i++) {
            if (s.at(i) != t.at(i)) {
                return t.at(i);
            }
        }
        return t.at(i);
    }
};
// @lc code=end

