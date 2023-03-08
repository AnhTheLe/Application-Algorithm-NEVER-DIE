#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

using namespace std;
#define MAX 1000

int m,n;
int Y[11][31];	//GV i va cac khoa hoc j
int A[MAX][2]; //Cac khoa hoc trung nhau
int c; 		// So ca trung nhau
int x[31];	// x[i] : GV day mon i
int load[11];	// load[i]: Số môn phân công cho gv i
int res;	// Ham muc tieu


void input() {
	int k;

	cin >> m >> n;
	for (int i=1; i<= m; i++) {
		cin >> k;
		Y[i][0] = k;
		for (int j=1; j<=k; j++)
		cin >> Y[i][k];
	}
	cin >> c;
	for (int x=1; x<=c; x++) {
		for (int y=1; y<=2; y++){
			cin >> A[x][y];
		}
	}
}

// Ktra 2 mon x,y co trung gio khong
bool checkTrung(int x, int y) {
	for (int i=1; i<=c; i++) {
		if ( (x == A[i][1] && y == A[i][2]) || (x == A[i][2] && y == A[i][1]) )
		return false;
	}
	return true;
}

// ktra gv t co trung gio day mon k voi mon truoc do khong
bool CheckGV(int t, int k) {
	for (int i=1; i<=k-1; i++) {
		if (checkTrung(i,k) && x[i]==t) return false;
	}
	return true;
}

void OKman() {
	int maxLoad = 0;
	for (int t=1; t<=m; t++)
	maxLoad = max(maxLoad, load[t]);
	if (maxLoad < res ) res = maxLoad;
}

void Try(int k) {
	for (int i=1; i<=m; i++) {
		for (int j=1; j<= Y[i][0]; j++) {
			if (Y[i][j] == k && CheckGV(i,k)){
				x[k] = i;
				load[i] +=1;
				if(k==n) OKman();
				else {
					if(load[i] < res)
					Try(k+1);
				}
				load[i] -=1;
			}
			break;
		}
	}
}

int main() {
	
	input();
	for(int i=1; i<=m; i++) {
		load[i] = 0;
	}
	res = 1e9;
	Try(1);
	cout << res;
	system("pause");

}
