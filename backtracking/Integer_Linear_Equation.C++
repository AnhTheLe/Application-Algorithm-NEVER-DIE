#include<bits/stdc++.h>
using namespace std;
const int MAX = 10000;
int f = 0;
int n, M; 
int dem;
int X[MAX];
int t[MAX];
int a[MAX];


void Try(int k){
    for (int i = 1; i <= (M - f - (t[n] - t[k]))/a[k]; i++)
    {
        X[k] = i;
        f  = f + X[k]*a[k];
        if(k == n){
            if (f == M) dem ++;
        }  
        else Try(k+1);
        f  = f - X[k]*a[k];
    }
}

int main(){
    dem = 0;
    cin >> n >> M;
    for (int i = 1; i <= n; i++){
       cin >> a[i];
    }
    t[1] = a[1];
    for (int i = 2; i <= n ;i++){
        t[i] = t[i-1] + a[i];  
    }
    Try(1);
    cout << dem;
    return 0;
}
