#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 显示选择对应的文字
void printChoice(int choice) {
    switch (choice) {
        case 1: cout << "石头"; break;
        case 2: cout << "剪刀"; break;
        case 3: cout << "布";   break;
    }
}

int main() {
    // 初始化随机数种子
    srand(time(0));

    int playerScore = 0, computerScore = 0;
    int round = 1;

    cout << "========================\n";
    cout << "  石头剪刀布大战 v1.0  \n";
    cout << "========================\n\n";

    while (true) {
        cout << "--- 第 " << round << " 回合 ---\n";
        cout << "请选择 (1=石头 2=剪刀 3=布 0=退出): ";

        int player;
        cin >> player;

        if (player == 0) break;
        if (player < 1 || player > 3) {
            cout << "输入无效，请重新选择！\n\n";
            continue;
        }

        // 电脑随机选择 1~3
        int computer = rand() % 3 + 1;

        cout << "你出了: ";
        printChoice(player);
        cout << "  电脑出了: ";
        printChoice(computer);

        // 判断胜负
        if (player == computer) {
            cout << "  → 平局!\n";
        } else if ((player == 1 && computer == 2) ||
                   (player == 2 && computer == 3) ||
                   (player == 3 && computer == 1)) {
            cout << "  → 你赢了!\n";
            playerScore++;
        } else {
            cout << "  → 电脑赢了!\n";
            computerScore++;
        }

        cout << "当前比分 - 你: " << playerScore
             << "  电脑: " << computerScore << "\n\n";
        round++;
    }

    cout << "\n======== 游戏结束 ========\n";
    cout << "最终比分 - 你: " << playerScore
         << "  电脑: " << computerScore << endl;

    if (playerScore > computerScore)
        cout << "恭喜你获得胜利!\n";
    else if (playerScore < computerScore)
        cout << "电脑获胜，再接再厉!\n";
    else
        cout << "平局!\n";

    system("pause");
    return 0;
}

