#include<bits/stdc++.h>
using namespace std;
const int MAX = 100 ;
int a[MAX], n;

void Merge(int a[], int p, int q, int r){
    int  n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    for(int i = 1 ; i <= n1; i++){
        L[i] = a[p+i-1];
    }  

    for (int j = 1; j <= n2; j++ ){
        R[j]= a[q+j];
    }

    L[n1+1] = 10000000;
    R[n2 + 1] = 100000000;

    int i,j;
    i = j = 1;
    for (int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j = j+1;
        }
    }
}



void Merge_Sort(int a[], int p, int r){
    if(p<r){
        int q = (p+r)/2;
        Merge_Sort(a, p,q);
        Merge_Sort(a,q+1, r);
        Merge(a, p,q,r);
    }

}

int main(){
    scanf("%d", &n);
    for(int i = 1; i<= n; i++){
        scanf("%d",&a[i]);
    }

    Merge_Sort(a, 1 ,n);
    for(int i = 1; i<= n; i++){
        cout<< a[i] << "\t";
    }
    return 0;
}