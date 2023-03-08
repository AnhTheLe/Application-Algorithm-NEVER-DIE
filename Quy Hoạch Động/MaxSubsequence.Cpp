#include<bits/stdc++.h>

using namespace std;
int n,A[1001];
int iMem[1001]; // iMem[i]: Biến luu giá trị của maxSum(i) là trọng số của đoạn có trọng số lớn nhất trong đoạn từ 1 -> i;
bool bMark[1001] = {false}; // bMark[i] check xem giá trị iMem[i] đã đưuọc gán chưa, nếu chưa thì trả về false;


// memset(bMark, 0, sizeof(bmark)); // Hàm lưu toàn bộ giá trị bMark[i] = false
//Hàm tính giá trị dãy con có tổng lớn nhất
int MaxSum(int i){
    if(i == 1) return A[i];
    if(bMark[i]) return iMem[i];
    int res = max(A[i],A[i] + MaxSum(i-1));
    iMem[i] = res;
    bMark[i] = true;
    return res;
}

void Trace(int i){
    if(i != 1 && iMem[i] == A[i] + iMem[i -1]){
         Trace(i-1);
    }
    cout << A[i] << " ";
}

int main(){
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> A[i];
    }
    cout << MaxSum(n);
    Trace(n);
    return 0;
}