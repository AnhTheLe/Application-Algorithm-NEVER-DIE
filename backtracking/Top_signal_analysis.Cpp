#include<bits/stdc++.h>
using namespace std;
const int Max = 1000000;
int a[Max];
int n, q = 0;
void input(){
    scanf("%d", &n);
    for(int i = 1; i<= n; i++){
        scanf("%d", &a[i]);
    }
}

void count(){
    for(int i = 2; i <= n-1; i++){
        if(a[i] > a[i-1] && a[i] > a[i+1]) q++;
    }
}

int main(){
    input();
    count();
    cout << q;
}