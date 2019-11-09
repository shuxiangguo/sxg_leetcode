/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (60.29%)
 * Likes:    343
 * Dislikes: 0
 * Total Accepted:    78.2K
 * Total Submissions: 129.6K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     return nums[nums.size() / 2];
    // }

    // 通过Boyer-Moore投票算法求解
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int candidate = 0;
        for (int num : nums) {
            if (cnt == 0) {
                candidate = num;
            }
            cnt += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
// @lc code=end

