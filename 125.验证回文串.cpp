/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (41.18%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    57.5K
 * Total Submissions: 139.7K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<cctype>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        // transform(s.begin(), s.end(), s.begin(), ::tolower);
        if (s.empty()) return true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            // i < j的条件不能漏了
            while (i < j && !isdigit(s[i]) && !isalpha(s[i])) {
                i++;
            }
            // 不能缺少条件i < j
            while (i < j && !isdigit(s[j]) && !isalpha(s[j])) {
                j--;
            }

            
            // if (s[i] >= 'A' && s[i] <= 'Z') {
            //     s[i] += 32;
            // }
            // if (s[j] >= 'A' && s[j] <= 'Z') {
            //     s[j] += 32;
            // }

            
            if (toupper(s[i]) != toupper(s[j])) return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};
// @lc code=end

