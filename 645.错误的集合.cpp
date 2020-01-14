/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 *
 * https://leetcode-cn.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (38.86%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 21.2K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 集合 S 包含从1到 n
 * 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。
 * 
 * 给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,2,4]
 * 输出: [2,3]
 * 
 * 
 * 注意:
 * 
 * 
 * 给定数组的长度范围是 [2, 10000]。
 * 给定的数组是无序的。
 * 
 * 
 */

// @lc code=start
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        map<int, int> mymap;

        for (auto num : nums) {
            mymap[num] += 1;
        }

        for (int i = 1; i < mymap.size()+1; i++) {
            if (mymap[i] > 1) {
                res.push_back(i);
            }
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (mymap[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

