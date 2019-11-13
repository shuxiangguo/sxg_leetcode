/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (50.49%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    11.4K
 * Total Submissions: 22.6K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 注意:
 * 假设字符串的长度不会超过 1010。
 * 
 * 示例 1: 
 * 
 * 
 * 输入:
 * "abccccdd"
 * 
 * 输出:
 * 7
 * 
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mymap;
        for (int i = 0; i < s.size(); i++) {
            mymap[s[i]]++;
        }

        int cnt = 0;
        int t = 0;
        for (int i = 0; i < mymap.size(); i++) {
            if (mymap[i] % 2 == 0) cnt += mymap[i];
            else {
                cnt += mymap[i] - 1;
                t = 1;
            }
        }
        return cnt + t;
        
    }
};
// @lc code=end

