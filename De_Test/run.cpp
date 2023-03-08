#include<bits/stdc++.h>
using namespace std ;

int n , sum = 1 ; 
int a[1000001];

int main ()
{
	cin >> n ; 
	a[0] = -1;
	for(int i = 1 ; i <= n ; i++)
	   cin >> a[i];
	for(int i = 1 ; i <= n ; i++)
	{
		if(a[i] <= a[i-1])
		   sum += 1 ; 
	}
	cout << sum ; 
}
