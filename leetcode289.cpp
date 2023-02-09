// 根据 百度百科 ， 生命游戏 ，简称为 生命 ，是英国数学家约翰·何顿·康威在 1970
// 年发明的细胞自动机。
//
// 给定一个包含 m ×
// n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：
// 1 即为 活细胞 （live），或 0 即为 死细胞
// （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
//
//     如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
//     如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
//     如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
//     如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
//
// 下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你
// m x n 网格面板 board 的当前状态，返回下一个状态。
//
// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/game-of-life
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <iostream>
#include <vector>
using namespace std;
void gameOfLife(vector<vector<int>> &board) {
  int m = board.size();
  int n = board[0].size();

  vector<vector<int>> ans(m, vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      int lives = 0;
      for (int r = i - 1; r <= i + 1; ++r) {
        for (int c = j - 1; c <= j + 1; ++c) {
          if (r < 0 || r >= m || c < 0 || c >= n || (r == i && c == j))
            continue;
          if (board[r][c])
            ++lives;
        }
      }
      if (board[i][j]) {
        if (lives == 2 || lives == 3) {
          ans[i][j] = 1;
        }
      } else {
        if (lives == 3) {
          ans[i][j] = 1;
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      board[i][j] = ans[i][j];
    }
  }
}
