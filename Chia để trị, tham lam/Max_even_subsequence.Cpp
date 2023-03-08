// Cho dãy số nguyên a1, a2, a3, ...
// ai, ai+1, ...aj
// dãy con chẵn là dãy con có trọng số chẵn
// y/c: tìm nhwungx dãy con có trọng số max

#include<iostream>
#include<math.h>
using namespace std;

const int MAX = 1000000;
int a[MAX];
int n;


void input(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++ ){
        scanf("%d", &a[i]);
    }
}

int MaxLeftMid(int i, int j){
    int s = 0;
    int maxLM = a[j];
    for(int k = j; k>=i ;k--){
        s += a[k];
        maxLM = max(s,maxLM);
    }
    return maxLM;
}

int MaxRightMid(int i, int j){
    int s = 0;
    int maxRM = a[i];
    for(int k = i; k <= j ;k++){
        s += a[k];
        maxRM = max(s,maxRM);
    }
    return maxRM;
}

int SubSeqMax(int i, int j){
    if( i == j ) return a[i];
    int mid = (n+1)/2;
    int wL = SubSeqMax(i, mid);
    int wR = SubSeqMax(mid+1, j);
    int maxLM = MaxLeftMid(1,mid);
    int maxRM = MaxRightMid(mid+1, j);
    int wM = maxLM + maxRM;
    int Max = max(max(wL,wR),wM);
    return Max;
 }

int main(){
    input();
    SubSeqMax(1,n);
    cout << SubSeqMax(1,n);
    return 0;
}