#include <QCoreApplication>

#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() < 1) {
            return -1;
        }
        //思路：左侧从0开始计算；右侧先算出所有数值的和，然后当索引i右移的时候rightSum减去对应索引的值就是i右侧所有数目的和
        //
        int len = nums.size();
        int j = 0, k = 0, leftSum = 0, rightSum = 0;
        for (int i = 0; i < len; ++i) {
            rightSum += nums[i];
        }
        for (int i = 0; i < len; ++i) {
            if (j < i) {
                leftSum += nums[j];
                ++j;
            }
            rightSum -= nums[k];
            k++;
            if (leftSum == rightSum) {
                return i;
            }
        }

        return -1;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //int arr[6] = {-1,-1,-1,0,1,1};
    int arr[6] = {1,7,3,6,4,7};
    vector<int> vi;
    for (int i = 0; i < 6; ++i) {
        vi.push_back(arr[i]);
    }

    Solution s;
    int i = s.pivotIndex(vi);
    printf("%d\n", i);

    return a.exec();
}
