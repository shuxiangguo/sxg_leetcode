/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.97%)
 * Likes:    723
 * Dislikes: 0
 * Total Accepted:    133.7K
 * Total Submissions: 382.2K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if (strs.empty()) return ans;
        if (strs.size() == 1) return strs.at(0);

        // 找最短的字符串
        string min = strs.at(0);
        for (int i = 1; i < strs.size(); i++) {
            if (strs.at(i).size() < min.size()) {
                min = strs.at(i);
            }
        }

        // 从第一个字符开始对比，直到找到不一样的
        for (int i = 0; i < min.size(); i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (min.at(i) != strs.at(j).at(i)) {
                    return ans;
                }
            }
            ans += min.at(i);
        }
        return ans;
    }
};
// @lc code=end

