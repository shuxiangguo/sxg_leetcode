/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (42.56%)
 * Likes:    298
 * Dislikes: 0
 * Total Accepted:    42.5K
 * Total Submissions: 99.7K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
        // 头结点和其他节点分开处理
    // ListNode* removeElements(ListNode* head, int val) {
    //     while (head != nullptr && head->val == val) {
    //         head = head->next;
    //     }

    //     if (head == nullptr) return head;
    //     ListNode *prev = head;
    //     // 确保当前节点后还有节点
    //     while (prev->next != nullptr) {
    //         if (prev->next->val == val) {
    //             prev->next = prev->next->next;
    //         } else {
    //             prev = prev->next;
    //         }
    //     }
    //     return head;
    // }

    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyNode = new ListNode(val-1);
        dummyNode->next = head;
        ListNode *prev = dummyNode;
        // 确保当前节点后面还有节点
        while (prev->next != nullptr) {
            if (prev->next->val == val) {
                prev->next = prev->next->next;
            } else {
                prev = prev->next;
            }
        }
        return dummyNode->next;
    }
};
// @lc code=end

