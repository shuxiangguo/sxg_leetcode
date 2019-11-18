/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小移动次数使数组元素相等
 *
 * https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (52.82%)
 * Likes:    80
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 12.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 n - 1 个元素增加 1。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [1,2,3]
 * 
 * 输出:
 * 3
 * 
 * 解释:
 * 只需要3次移动（注意每次移动会增加两个元素的值）：
 * 
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt = 0;
        int minValue = nums[0];
        for (auto& num : nums) {
            if (num < minValue) {
                minValue = num;
            }
        }
        for (auto& num : nums) {
            cnt += (num - minValue);
        }
        return cnt;
    }
};
// @lc code=end

