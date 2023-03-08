#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
int n;
pair<int, int> x[MAX];

// Hàm so sánh theo phần tử second
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
void Gready() {
    int count = 0; // Kết quả
    int last = -1; // Điểm kết thúc của đoạn gần nhất
    sort(x+1, x+n+1,cmp); // Hàm sort theo cmp
    
    for (int i = 1; i <= n; i++)
        if (x[i].first > last){ // So sánh với điểm kết thúc của đoạn chọn gần nhất
            count++;
            last = x[i].second;
        }
    
    cout << count << endl;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> x[i].first >> x[i].second;
    Gready();
    return 0;
}