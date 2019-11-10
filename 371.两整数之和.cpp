/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 *
 * https://leetcode-cn.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (52.35%)
 * Likes:    161
 * Dislikes: 0
 * Total Accepted:    17.5K
 * Total Submissions: 33.4K
 * Testcase Example:  '1\n2'
 *
 * 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
 * 
 * 示例 1:
 * 
 * 输入: a = 1, b = 2
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: a = -2, b = 3
 * 输出: 1
 * 
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        while (b)
         {
            auto carry = ((unsigned int ) (a & b))<<1 ; // 记录a+b的进位，直到进位为0是退出
            a = a^b;   //结果相加
            b = carry;  //循环
        }
        return a;
    }
};
// @lc code=end

