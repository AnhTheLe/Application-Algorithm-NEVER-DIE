#include<bits/stdc++.h>

using namespace std;

int D[11]; // Mảng lưu các đồng tiền mệnh giá D[i]
int iMem[11][1001];
memset(iMem, -1, sizeof(iMem));

// Hàm tính số lượng tiền ít nhất để đổi đc tờ tiên mệnh giá x khi chỉ sử dụng các tờ từ D1 -> Di 
int MinCoin(int i, int x){
    if(x < 0) return INT32_MAX;
    if(x == 0) return 0;
    if(i == 0) return INT32_MAX;

    if(iMem[i][x] != -1) return iMem[i][x];
    int res = INFINITY;
    res = min(res , 1+ MinCoin(i, x - D[i]));
    res = min(res, MinCoin[i-1, x]);
    iMem[i][x] = res;
    return res;
}