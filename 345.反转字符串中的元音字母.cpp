/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (47.99%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    17.6K
 * Total Submissions: 36.6K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */

// @lc code=start
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vec {'a', 'e', 'i', 'o', 'u'};
        transform(s.begin(), s.end(), s.begin(), tolower);
        if (s.size() > 0) {
            auto first = s.begin();
            auto last = s.end() - 1;
            while (first < last) {
                while (find(vec.begin(), vec.end(), *first) == vec.end()) {
                    first++;
                }

                while (find())
            }
        }
    }
};
// @lc code=end

