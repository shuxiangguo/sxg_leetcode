/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (41.26%)
 * Likes:    154
 * Dislikes: 0
 * Total Accepted:    48.2K
 * Total Submissions: 116.5K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 案例:
 * 
 * 
 * s = "leetcode"
 * 返回 0.
 * 
 * s = "loveleetcode",
 * 返回 2.
 * 
 * 
 * 
 * 
 * 注意事项：您可以假定该字符串只包含小写字母。
 * 
 */

// @lc code=start
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mymap;
        for (auto x : s) {
            mymap[x]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (mymap[s[i]] != 1) continue;
            else return i;
        }
        return -1;
    }
};
// @lc code=end

