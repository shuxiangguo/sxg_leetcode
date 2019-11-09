/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (30.42%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    30.5K
 * Total Submissions: 99.7K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int num) {
        vector<bool> vec(num ,true);
        int cnt = 0;
        for (int i = 2; i < num; i++) {
            if (vec[i]) cnt++;
            for (int j = i+i; j < num; j+=i) {
                vec[j] = false;
            }
        }
        return cnt;
    }
};
// @lc code=end

