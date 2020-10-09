#include <QCoreApplication>

/*
 * 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入:
    Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
输出:
合并后的树:
         3
        / \
       4   5
      / \   \
     5   4   7
注意: 合并必须从两个树的根节点开始。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-binary-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:    
    TreeNode *addPoints(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) {
            return nullptr;
        }
        if (!t1) {
            return new TreeNode(t2->val);
        }
        if (!t2) {
            return new TreeNode(t1->val);
        }
        return new TreeNode(t1->val + t2->val);
    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return nullptr;
        }
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        TreeNode * t3 = new TreeNode(t1->val + t2->val);
        TreeNode *l3 = t3, *r3 = t3;
        TreeNode *temp1 = t1->left, *temp2 = t2->left;
        while (temp1 || temp2) {
            l3->left = addPoints(temp1, temp2);
            if (temp1)
                temp1 = temp1->left;
            if (temp2)
                temp2 = temp2->left;
            l3 = l3->left;
        }
        temp1 = t1->right, temp2 = t2->right;
        while (temp1 || temp2) {
            l3->right = addPoints(temp1, temp2);
            if (temp1)
                temp1 = temp1->right;
            if (temp2)
                temp2 = temp2->right;
            l3 = l3->right;
        }

        return t3;
    }

    void print(TreeNode *t) {
        if (!t) {
            return;
        }
        printf("%d\n", t->val);
        print(t->left);
        print(t->right);
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TreeNode * t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->left->left = new TreeNode(5);
    t1->right = new TreeNode(2);

    TreeNode *t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->left->right = new TreeNode(4);
    t2->right = new TreeNode(3);
    t2->right->right = new TreeNode(7);

    Solution s;
    TreeNode *t3 = s.mergeTrees(t1, t2);

    s.print(t1);
    printf(".................\n");
    s.print(t2);
    printf(".................\n");
    s.print(t3);

    return a.exec();
}
