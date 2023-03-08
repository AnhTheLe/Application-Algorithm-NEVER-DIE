// Dao Trong Hoan
// 20204974
// MAZE

#include <bits/stdc++.h>

using namespace std;

const int maxN = 999;
const int oo = 1e9 + 1;
typedef pair<int, int> ii;

queue<ii> qe;
int m, n;          // Kích thước ma trận
int r, c;          // Tọa độ ban đầu
int a[maxN][maxN]; // Đánh dấu ô đó đã được xét chưa
int d[maxN][maxN]; // Chứa khoảng cách ngắn nhất từ vị trí bắt đầu
int dX[] = {0, 0, 1, -1};
int dY[] = {1, -1, 0, 0};

int solve()
{
    qe.push(ii(r, c));  // Thêm vị trí ban đầu vào hàng đợi
    d[r][c] = 0;        // Khoảng cách bằng 0
    a[r][c] = 1;        // Đánh dấu đã xét vị trí ban đầu
    while (!qe.empty()) // Khi hàng đợi còn phần tử thì còn xét
    {
        ii u = qe.front();          // Lấy ra phần tử đầu
        qe.pop();                   // Xóa phần tử đầu
        for (int i = 0; i < 4; i++) // Xét các trường hợp lần lượt phải, trái, xuống, lên
        {
            int x = dX[i] + u.first;
            int y = dY[i] + u.second;
            if (x < 1 || x > m || y < 1 || y > n) // Nếu chạm tường thì thoát khỏi vòng lặp
            {
                return d[u.first][u.second] + 1;
            }

            if (a[x][y] != 1) // Kiểm tra nếu ô đó chưa xét
            {
                d[x][y] = d[u.first][u.second] + 1; // Tăng khoảng cách thêm 1
                qe.push(ii(x, y));                  // Thêm vào hàng đợi
                a[x][y] = 1;                        // Đánh dấu sẽ xét ô đó
            }
        }
    }
    return -1;
}

int main()
{
    cin >> m >> n >> r >> c;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    cout << solve();
    return 0;
}
