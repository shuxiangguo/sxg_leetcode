
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 解法1
class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 1;
        int len2 = 1;

        ListNode* p = l1;
        ListNode* q = l2;

        // 获取l1的长度
        while (p->next != nullptr) {
            len1++;
            p = p->next;
        }

        // 获取l2的长度
        while(q->next != nullptr) {
            len2++;
            q = q->next;
        }

        // l1较长，在l2末尾补零
        if (len1 > len2) {
            for (int i = 1; i <= len1-len2; i++) {
                q->next = new ListNode(0);
                q = q->next;
            }
        }

        // l2较长，在l1末尾补零
        if (len2 > len1) {
            for (int i = 1; i <= len2 - len1; i++) {
                p->next = new ListNode(0);
                p = p->next;
            }
        }

        p = l1;
        q = l2;

        bool count = false; // 记录进位
        // 存放结果的链表
        ListNode* l3 = new ListNode(-1);
        ListNode* w = l3; // l3的移动指针
        int i = 0; // 记录相加结果
        while (p != nullptr && q != nullptr) {
            i = count + p->val + q->val;
            w->next = new ListNode(i%10);
            count = i >= 10 ? true : false;
            w = w->next;
            p = p->next;
            q = q->next;
        }

        // 
        if (count) {
            w->next = new ListNode(1);
            w = w->next;
        }
        return l3->next;

    }
};


// 解法2
class Solution2 {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1); // 存放结果的链表
        ListNode* h = head; // head的移动指针

        int sum = 0; // 每个对应位和进位的相加和
        bool carry = false; // 是否有进位
        while (l1 != nullptr || l2 != nullptr) {
            sum = 0;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            if (carry) {
                sum++;
            }

            h->next = new ListNode(sum % 10);
            h = h->next;
            carry = sum >= 10 ? true : false;
        }

        if (carry) {
            h->next = new ListNode(1);
        }
        return head->next;
    }
};
