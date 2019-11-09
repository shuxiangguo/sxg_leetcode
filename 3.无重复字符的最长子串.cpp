/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
# include<iostream>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        set<char> myset;
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            // try to extend the range[i, j]
            if (!myset.count(s[j])) {
                myset.insert(s[j++]);
                ans = max(ans, j-i);
            } else {
                myset.erase(s[i++]);
            }
        }
        return ans;
    }
};
// @lc code=end

