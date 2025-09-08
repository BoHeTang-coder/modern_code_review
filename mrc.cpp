#include <iostream>
using namespace std; // 原代码缺失命名空间，需补充

// 判断是否获胜（原函数逻辑正确，保留不变）
bool isWin(char game[3][3]) {
    bool win = false;
    // 检查行
    if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true;
    if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true;
    // 检查列
    if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true;
    if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    // 检查对角线
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    return win;
}


int main() {
    int i, j;
    // 1. 修复棋盘初始化：原代码仅第一个元素为空格，其余为'\0'，现全部初始化为空格
    char game[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player1 = 'X', player2 = 'O';
    // 2. 优化回合控制逻辑：turn=false=玩家1（X），turn=true=玩家2（O），玩家1先出
    bool turn = false; 
    bool gameOver = false;

    // 3. 修复循环逻辑：用while循环替代for，支持重复输入无效坐标（不消耗回合）
    int totalSteps = 0; // 统计总步数，最多9步（平局）
    while (totalSteps < 9 && !gameOver) {
        turn = !turn; // 切换回合
        // 提示当前玩家输入
        if (turn == false) {
            cout << "\n玩家1（X）请落子：";
        } else {
            cout << "\n玩家2（O）请落子：";
        }
        cout << "输入坐标（行 列，如1 1代表第一行第一列）：";
        cin >> i >> j;

        // 4. 修复坐标转换与合法性检查
        // （1）输入坐标1-3转数组下标0-2（原代码直接用1-3导致数组越界）
        i--; 
        j--;
        // （2）检查坐标是否在合法范围（0-2）
        if (i < 0 || i >= 3 || j < 0 || j >= 3) {
            cout << "错误：坐标必须在1-3之间！请重新输入" << endl;
            turn = !turn; // 回滚回合（未成功落子，不切换玩家）
            continue;
        }

        // 5. 落子（合法输入才执行）
        if (turn == false) {
            game[i][j] = player1;
        } else {
            game[i][j] = player2;
        }
      
     
        // 7. 判断是否获胜
        if (isWin(game)) {
            if (turn == false) {
                cout << "\n恭喜！玩家1（X）获胜！" << endl;
            } else {
                cout << "\n恭喜！玩家2（O）获胜！" << endl;
            }
            gameOver = true;
        }
    }

    // 8. 修复平局判断：总步数满9步且未分胜负（原代码用i==3判断逻辑错误）
    if (totalSteps >= 9) {
        cout << "\n游戏结束，双方平局！" << endl;
    }

    return 0;
}
