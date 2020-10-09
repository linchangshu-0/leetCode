#include <QCoreApplication>
/*
701. 二叉搜索树中的插入操作
给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据保证，新值和原始二叉搜索树中的任意节点值都不同。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。



例如,

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和 插入的值: 5
你可以返回这个二叉搜索树:

         4
       /   \
      2     7
     / \   /
    1   3 5
或者这个树也是有效的:

         5
       /   \
      2     7
     / \
    1   3
         \
          4


提示：

给定的树上的节点数介于 0 和 10^4 之间
每个节点都有一个唯一整数值，取值范围从 0 到 10^8
-10^8 <= val <= 10^8
新值和原始二叉搜索树中的任意节点值都不同
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return root;
        }
        if (val > root->val) {
            TreeNode *t = root->right;
            if (!t) {
                root->right = new TreeNode(val);
                return root;
            }
            while (t) {
                //t有左子树且有值
                if (val < t->val && t->left && val >= t->left->val) {
                    TreeNode *left = t->left;
                    t->left = new TreeNode(val);
                    t->left->left = left;
                    return root;
                }
                //t无左子树
                if (val < t->val && !t->left) {
                    t->left = new TreeNode(val);
                    return root;
                }
                //t有右子树且有值
                if (val > t->val && t->right && t->right->val <= val) {
                    TreeNode *temp = t->right;
                    t->right = new TreeNode(val);
                    t->right->right = temp;
                    return root;
                }
                //t无右子树
                if (val > t->val && !t->right) {
                    t->right = new TreeNode(val);
                    return root;
                }
                if (val < t->val) {
                    t = t->left;
                }
                if (val > t->val) {
                    t = t->right;
                }
            }
        }

        if (val < root->val) {
            TreeNode *t = root->left;
            if (!t) {
                root->left = new TreeNode(val);
                return root;
            }
            while (t) {
                //t有左子树且有值
                if (val < t->val && t->left && val > t->left->val) {
                    TreeNode *left = t->left;
                    t->left = new TreeNode(val);
                    t->left->left = left;
                    return root;
                }
                //t无左子树
                if (val < t->val && !t->left) {
                    t->left = new TreeNode(val);
                    return root;
                }
                //t有右子树且有值
                if (val > t->val && t->right && val > t->right->val) {
                    TreeNode *temp = t->right;
                    t->right = new TreeNode(val);
                    t->right->right = temp;
                    return root;
                }
                //t无右子树
                if (val > t->val && !t->right) {
                    t->right = new TreeNode(val);
                    return  root;
                }
                if (val < t->val) {
                    t = t->left;
                }
                if (val > t->val) {
                    t = t->right;
                }
            }
        }
    }
};

void printTree(TreeNode *t) {
    if (!t) {
        return;
    }
    printf("%d\n", t->val);
    printTree(t->left);
    printTree(t->right);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TreeNode *t = new TreeNode(4);
    t->left = new TreeNode(2);
    t->left->left = new TreeNode(1);
    t->left->right = new TreeNode(3);

    t->right = new TreeNode(7);

    Solution s;
    s.insertIntoBST(t, 0);

    printTree(t);

    return a.exec();
}
