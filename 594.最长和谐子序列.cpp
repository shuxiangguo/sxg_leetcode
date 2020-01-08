/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 *
 * https://leetcode-cn.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (43.40%)
 * Likes:    65
 * Dislikes: 0
 * Total Accepted:    6.6K
 * Total Submissions: 15K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * 和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
 * 
 * 现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,2,2,5,2,3,7]
 * 输出: 5
 * 原因: 最长的和谐数组是：[3,2,2,2,3].
 * 
 * 
 * 说明: 输入的数组长度最大不超过20,000.
 * 
 */

// @lc code=start

/**
 * 
 *只需要考虑比其大的元素即可，因为每个都这样考虑 
 * 
 */
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> mymap;
        for (auto num : nums) {
            mymap[num] += 1;
        }

        int res = 0;
        for (auto num : nums) {
            if (mymap[num+1] != 0 ) {
                res = max(res, mymap[num]+mymap[num+1]);
            }
        }
        return res;
    }
};
// @lc code=end

