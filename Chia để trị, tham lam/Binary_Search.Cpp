#include<bits/stdc++.h>
using namespace std;
int x,n;
vector<int> A;

bool Binnary_search(const vector<int> &A, int lo, int hi, int x){
    if( lo < hi) return false;
    int mid = (hi + lo)/2;
    if( x == mid ) return true;
    if( x < mid ) return Binnary_search(A,lo, mid - 1, x);
    if(x > mid) return Binnary_search(A,mid + 1, hi, x);
}

int main(){
    scanf("%d", &x);
    scanf("%d", &n);
    int temp;
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        A.insert(i,temp);
    }
    sort(A.begin(), A.end());
    if(Binnary_search(A, 1, n, x) == true) cout << "True";
    return 0;
}