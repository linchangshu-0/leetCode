#include <QCoreApplication>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return head;
        }

        ListNode *t = head, *n = head->next;
        if (n == t) {
            return t;
        }
        if (!n) {
            return n;
        }
        n = n->next;
        while (t) {
            if (n == t) {
                return t;
            }
            if (!n) {
                return n;
            }
            n = n->next;
            t = t->next;
        }
        return t;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
