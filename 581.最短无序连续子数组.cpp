/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (33.11%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 42.8K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 
 * 你找到的子数组应是最短的，请输出它的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [2, 6, 4, 8, 10, 9, 15]
 * 输出: 5
 * 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 * 
 * 
 * 说明 :
 * 
 * 
 * 输入的数组长度范围在 [1, 10,000]。
 * 输入的数组可能包含重复元素 ，所以升序的意思是<=。
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_copy(nums);
        sort(nums.begin(), nums.end());
        int start = nums.size(), end = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums_copy[i]) {
                start = min(start, i);
                end = max(end, i);
            }
        }
        return (end - start) >= 0? end - start +  1 : 0;
    }
};
// @lc code=end

