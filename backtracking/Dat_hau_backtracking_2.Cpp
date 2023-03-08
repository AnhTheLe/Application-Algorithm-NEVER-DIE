#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
int n, a[MAX];
int 
int dem = 0;
// a[i] là quân hâu đặt ở hàng i, cột a[i] ( hay a[i] là số cột)
void solution(){
    dem++;
}

bool Check(int k, int i){
    // Duyệt các hàng từ 1 tới k để kiểm tra
    for (int j = 1; j < k ; j++){
        if(a[j] == i || a[j] + j == i + k || a[j] - j == i - k) return false;
    }
    return true;
}

// đặt quân hậu ở dòng thứ k
void Try(int k){
    if (k > n) { solution(); return;}
    else{
        for (int i = 1; i <= n; i++){
            if(Check(k,i) == true){
                a[k] = i; //  dòng k cột i
                Try(k+1);
            }
        }
    }
}

int main(){
    n =  4;
    Try(1);
    cout << dem;

}