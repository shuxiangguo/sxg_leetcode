/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (38.95%)
 * Likes:    294
 * Dislikes: 0
 * Total Accepted:    44.1K
 * Total Submissions: 113.2K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next) return true;
        ListNode*pre = NULL;
        ListNode*slow = head;
        ListNode*fast = head;
        ListNode*s = NULL;
        while(fast != NULL && fast->next != NULL)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
            pre->next = s;
            s = pre;
        }
        ListNode*temp = slow;
        if(fast != NULL) temp = temp->next; 
        slow = pre;
        while(temp!=NULL)
            if(temp->val!=slow->val) return false;
            else {temp = temp->next;slow = slow->next;}
        return true;
    }
};
// @lc code=end

