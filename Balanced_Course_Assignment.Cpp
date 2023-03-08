#include<bits/stdc++.h>
using namespace std;
#define N 50
vector<int> T[N];               // T[i] là danh sách giáo viên có thể được chỉ định vào khóa học i
int n, m;                       // n khóa học, m giáo viên
bool conflict[N][N];            // hai môn có mâu thuẫn nhau ko; if mâu thuẫn -> true
int x[N];                       // X[i] là giáo viên đc phân công dạy môn i 
int load[N];                    // Load[t]: số môn được phân công cho giáo viên t
int res;                        // giá trị hàm mục tiêu tối ưu 
void input(){
    cin >> m >> n;              // nhập số nguyên m,n
    for(int i = 1; i <= m; i++){
        int k; cin >> k;        // nhập số nguyên k
        for (int j = 1; j<=k; j++){
            int c;  cin >> c;   T[c].push_back(i);  //Nhập k số nguyên dương cho biết khóa học mà giáo viên i dạy
        }
    }

    int K; 
    for (int i = 1; i <= n; i++){
        for(int j =1; j <= n; j++)  conflict[i][j] = false; // Đầu tiên gán toàn bộ khóa học đôi 1 KHÔNG mâu thuẫn nhau
    }

    cin >> K;                   // nhập số nguyên K ở dòng m+2
    for (int k = 1; k <= K; k++ ){
        int i,j;
        cin >> i >> j;          // nhập hai khóa học i, j mâu thuẫn nhau
        conflict[i][j] = true;
        conflict[j][i] = true;
    }

}

// check xem các môn mà giáo viên t dạy có môn nào mâu thuẫn với môn k không; if có -> false
bool check(int t, int k){         
    for(int i = 1; i <= k-1; i++){
        if(conflict[i][k] && x[i] == t) return false;
    }
    return true;
}

void solution(){
    int maxLoad = 0;
    for(int t = 1; t <= m; t++ ){
        maxLoad = max(maxLoad, load[t]);
    }

    res = max(maxLoad,res);
}

void Try(int k){
    for(int i = 0; i < T[k].size(); i++ ){
        int t = T[k][i];
        if(check(t,k)){
            x[k] = t;
            load[t] += 1;
            if(k == n) solution();
            else{
                if(load[t] < res)   Try(k+1);
            }
            load[t] -= 1;
        }
    }
}

int main(){
    input();
    for(int t = 1; t <= m; t++) load[t] = 0;
    res = 1e9;
    Try(1);
    cout << res;
    return 0;
}
