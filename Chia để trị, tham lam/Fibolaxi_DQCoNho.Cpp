#include<bits/stdc++.h>

using namespace std;

map<int, int> Mem;
int fibolaxi(int n){
    if(n <= 2) return 1;
    if(Mem.find(n) != Mem.end()) return Mem[n];
    int res = fibolaxi(n-1) + fibolaxi(n-2);
    Mem[n] = res;
    return res;
}
int main(){
    cout<< fibolaxi(20);
    return 0;
}
