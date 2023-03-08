#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n;
int a[MAX], b[MAX];
int last,dem = 0;
void input(){
    scanf("%d",&n);
    for(int i = 1; i<= n; i++){
        scanf("%d %d", &a[i], &b[i]);
    }
}

void quickSort(int a[],int b[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
			int temp1 = a[i];
			a[i] = a[j];
			a[j] = temp1;

            int temp2 = b[i];
			b[i] = b[j];
			b[j] = temp2;
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(a,b, i, r);
	}
	if (l < j){
		quickSort(a,b, l, j);
	}
}

void Disjoint_segment(){
    quickSort(b,a,1,n);
    last = -1;
    for(int i = 1; i <= n; i++){
		if(last < a[i]){
            last = b[i];
            dem ++;
        }
    }
}

int main(){

    input();
    Disjoint_segment();
    cout << dem;
    return 0;
}