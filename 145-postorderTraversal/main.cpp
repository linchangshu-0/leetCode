#include <QCoreApplication>
#include <vector>
using namespace std;

/*
145. 二叉树的后序遍历
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> vi;
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return vi;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        vi.push_back(root->val);

        return vi;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(4);
    t->right = new TreeNode(2);
    t->right->left = new TreeNode(3);

    Solution s;
    vector<int> vi = s.postorderTraversal(t);
    for (int i = 0; i < vi.size(); ++i) {
        printf("%d ", vi[i]);
    }
    printf("\n");

    return a.exec();
}
