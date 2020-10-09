#include <QCoreApplication>
#include <vector>
using namespace std;

/*给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。



示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vi;
        vector<int> ret;
        bool bFind = false;
        int index = 0;
        while (index < nums.size()) {
            vi.clear();
            ret.clear();
            vi.push_back(nums[index]);
            ret.push_back(index);
            for (int i = 0; i < nums.size(); ++i) {
                if (vi[0] + nums[i] == target && i != index) {
                    ret.push_back(i);
                    return ret;
                }
            }
            ++index;
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<int> vi;
    vi.push_back(-3);
    vi.push_back(-4);
    vi.push_back(3);
    vi.push_back(9);
    vi.push_back(-5);

    Solution s;
    vector<int> ret = s.twoSum(vi, 0);
    for (int i = 0; i < ret.size(); ++i) {
        printf("%d ", ret[i]);
    }
    printf("\n");

    return a.exec();
}
