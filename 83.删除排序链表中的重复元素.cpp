/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (47.86%)
 * Likes:    210
 * Dislikes: 0
 * Total Accepted:    49.5K
 * Total Submissions: 103.4K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
 */

// @lc code=start

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
//  };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curNode = head;
        ListNode *tmp = nullptr;
        while (curNode != nullptr && curNode->next != nullptr) {
            if (curNode->val == curNode->next->val) {
                tmp = curNode->next;
                curNode->next = curNode->next->next;
                tmp = nullptr;
            } else {
                curNode =curNode->next;
            }
        }
        return head;
    }
};
// @lc code=end

