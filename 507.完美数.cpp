/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 *
 * https://leetcode-cn.com/problems/perfect-number/description/
 *
 * algorithms
 * Easy (36.18%)
 * Likes:    38
 * Dislikes: 0
 * Total Accepted:    9K
 * Total Submissions: 24.6K
 * Testcase Example:  '28'
 *
 * 对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。
 * 
 * 给定一个 整数 n， 如果他是完美数，返回 True，否则返回 False
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: 28
 * 输出: True
 * 解释: 28 = 1 + 2 + 4 + 7 + 14
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 输入的数字 n 不会超过 100,000,000. (1e8)
 * 
 */

// @lc code=start
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 0) return false;
        bool res = false;
        set<int> vec;
        for (int i = 1; i <= num / 2; i++) {
            if (num % i == 0) {
                vec.insert(i);
                vec.insert(num / i);
            }
        }

        int result = 0;
        for (auto it = vec.begin(); it != vec.end(); it++) {
            result += *it;
        }
        if (result == 2*num) res = true;
        return res;
    }
};
// @lc code=end

