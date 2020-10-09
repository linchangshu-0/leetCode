#include <QCoreApplication>
#include <vector>
using namespace std;
/*
37. 解数独
编写一个程序，通过填充空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。

53  7
6  195
 98    6
8   6   3
4  8 3  1
7   2   6
 6    28
   419  5
    8  79

一个数独。
534678912
672195348
198342567
859761423
426853791
713924856
961537284
287419635
345286179

答案被标成红色。

提示：

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<vector<char>> vvi;
    vector<char> vi;
    vi.push_back('5');vi.push_back('3');vi.push_back(' ');vi.push_back(' ');vi.push_back('7');
    vi.push_back(' ');vi.push_back(' ');vi.push_back(' ');vi.push_back(' ');
    vvi.push_back(vi);vi.clear();
    vi.push_back('6');vi.push_back(' ');vi.push_back(' ');vi.push_back('1');vi.push_back('9');
    vi.push_back('5');vi.push_back(' ');vi.push_back(' ');vi.push_back(' ');
    vvi.push_back(vi);vi.clear();
    vi.push_back(' ');vi.push_back('9');vi.push_back('8');vi.push_back(' ');vi.push_back(' ');
    vi.push_back(' ');vi.push_back(' ');vi.push_back('6');vi.push_back(' ');
    vvi.push_back(vi);vi.clear();
    vi.push_back('8');vi.push_back(' ');vi.push_back(' ');vi.push_back(' ');vi.push_back('6');
    vi.push_back(' ');vi.push_back(' ');vi.push_back(' ');vi.push_back('3');
    vvi.push_back(vi);vi.clear();
    vi.push_back('4');vi.push_back(' ');vi.push_back(' ');vi.push_back('8');vi.push_back(' ');
    vi.push_back('3');vi.push_back(' ');vi.push_back(' ');vi.push_back('1');
    vvi.push_back(vi);vi.clear();
    vi.push_back('7');vi.push_back(' ');vi.push_back(' ');vi.push_back(' ');vi.push_back('2');
    vi.push_back(' ');vi.push_back(' ');vi.push_back(' ');vi.push_back('6');
    vvi.push_back(vi);vi.clear();
    vi.push_back(' ');vi.push_back('6');vi.push_back(' ');vi.push_back(' ');vi.push_back(' ');
    vi.push_back(' ');vi.push_back('2');vi.push_back('8');vi.push_back(' ');
    vvi.push_back(vi);vi.clear();
    vi.push_back(' ');vi.push_back(' ');vi.push_back(' ');vi.push_back('4');vi.push_back('1');
    vi.push_back('9');vi.push_back(' ');vi.push_back(' ');vi.push_back('5');
    vvi.push_back(vi);vi.clear();
    vi.push_back(' ');vi.push_back(' ');vi.push_back(' ');vi.push_back(' ');vi.push_back('8');
    vi.push_back(' ');vi.push_back(' ');vi.push_back('7');vi.push_back('9');
    vvi.push_back(vi);vi.clear();
    for (int i = 0; i < vvi.size(); ++i) {
        for (int j = 0; j < vvi[i].size(); ++j) {
            printf("%c", vvi[i][j]);
        }
        printf("\n");
    }

    return a.exec();
}
