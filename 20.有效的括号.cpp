/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (39.79%)
 * Likes:    1112
 * Dislikes: 0
 * Total Accepted:    137.7K
 * Total Submissions: 346K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        string bracketLeft = "{[(";
        string bracketRight = "}])";
        stack<char> sta;
        for (int i = 0; i < s.size(); i++) {
            char ch = s.at(i);
            int indexLeft = -1, indexRight = -2;
            indexLeft = bracketLeft.find(ch);
            indexRight = bracketRight.find(ch);

            // 是左括号
            if (indexLeft >= 0) {
                sta.push(ch);
            } else if (indexRight >= 0) {
                // 匹配成功
                if (!sta.empty() && sta.top() == bracketLeft[indexRight]) {
                    sta.pop();
                } else {
                    return false;
                }
            }
        }
        return sta.empty();
    }
};
// @lc code=end

