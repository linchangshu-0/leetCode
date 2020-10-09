#include <QCoreApplication>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int nLen = s.size();
        if (nLen % 2 == 0) {
            //字符串长度为偶数
            for (int i = 0; i < nLen / 2; ++i) {
                char temp = s[i];
                s[i] = s[nLen - 1 - i];
                s[nLen - 1 - i] = temp;
            }
        } else {
            //字符串长度为奇数
            for (int i = 0; i < nLen / 2 + 1; ++i) {
                char temp = s[i];
                s[i] = s[nLen - 1 - i];
                s[nLen - 1 - i] = temp;
            }
        }
        return;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char arr[6] = {'h', 'e', 'l', 'l', 'o', 'w'};
    vector<char> vc;
    for (int i = 0; i < 6; ++i) {
        vc.push_back(arr[i]);
    }
    Solution s;
    s.reverseString(vc);
    for (int i = 0; i < 6; ++i) {
        printf("%c ", vc[i]);
    }
    printf("\n");

    return a.exec();
}
