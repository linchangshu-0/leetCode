#include <QCoreApplication>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() < 1) {
            return 0;
        }
        if (target <= nums[0]) {
            return 0;
        }
        if (target > nums[nums.size() - 1]) {
            return nums.size();
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (target == nums[i]) {
                return i;
            }
            if (target > nums[i]) {
                if (target == nums[i + 1]) {
                    return i + 1;
                }
                if (target < nums[i + 1]) {
                    return i + 1;
                }
            }
        }
        return nums.size();
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int arr[4] = {1, 3, 5, 6};
    vector<int> vi;
    for (int i = 0; i < 4; ++i) {
        vi.push_back(arr[i]);
    }
    Solution s;
    int i = s.searchInsert(vi, 0);
    printf("%d\n", i);

    return a.exec();
}
