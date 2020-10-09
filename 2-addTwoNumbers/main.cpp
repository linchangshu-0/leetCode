#include <QCoreApplication>

/*
2. 两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *addThreeNumbers(ListNode *l1, ListNode *l2, ListNode *step) {
        if (!l1 && !l2) {
            if (!step) {
                return 0;
            }
            return new ListNode(step->val);
        }
        if (!l1) {
            if (!step) {
                return new ListNode(l2->val);
            }
            return new ListNode(l2->val + step->val);
        }
        if (!l2) {
            if (!step) {
                return new ListNode(l1->val);
            }
            return new ListNode(l1->val + step->val);
        }
        if (!step) {
            return new ListNode(l1->val + l2->val);
        }
        return new ListNode(l1->val + l2->val + step->val);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }

        ListNode *root = 0;
        ListNode *l = new ListNode(l1->val + l2->val);
        if (!root) {
            root = l;
        }
        while (true) {
            ListNode *step = 0;
            if (l->val >= 10) {
                int val = l->val / 10;
                l->val = l->val - 10;
                step = new ListNode(val);
            }
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            l->next = addThreeNumbers(l1, l2, step);
            l = l->next;
            if (!l1 && !l2) {
                break;
            }
        }

        return root;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ListNode *l = new ListNode(2);
    l->next = new ListNode(4);
    l->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode *l3 = s.addTwoNumbers(l, l2);
    while (l3) {
        printf("%d ", l3->val);
        l3 = l3->next;
    }
    printf("\n");

    return a.exec();
}
