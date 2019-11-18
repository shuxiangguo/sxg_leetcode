/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 *
 * https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (54.01%)
 * Likes:    229
 * Dislikes: 0
 * Total Accepted:    18.4K
 * Total Submissions: 34.1K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
 * 
 * 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
 * 
 * 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [4,3,2,7,8,2,3,1]
 * 
 * 输出:
 * [5,6]
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    // vector<int> findDisappearedNumbers(vector<int>& nums) {
    //     vector<int> vec;
    //     int n = nums.size();
    //     unordered_map<int, int> mymap(n+1);
    //     for (auto& num : nums) {
    //         mymap[num] = 1;
    //     }

    //     for (int i = 1; i <= n; i++) {
    //         if (mymap[i] < 1) {
    //             vec.push_back(i);
    //         }
    //     }
    //     return vec;
    // }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) return res;
        for (int i = 0; i < nums.size(); i++) {
            int index = (nums[i] - 1) % nums.size();
            nums[index] += nums.size();
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= nums.size()) res.push_back(i+1);
        }
        return res;
    }
};
// @lc code=end

