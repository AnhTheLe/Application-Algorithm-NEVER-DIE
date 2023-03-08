#include<bits/stdc++.h>
using namespace std ;

int a[7], n , sum = 0 ; 

/* 
a[0] : H 
a[1] : U
a[2] : S
a[3] : T
a[4] : O
a[5] : I
a[6] : C
*/

int hust()
{
	return 1000 * a[0] + 100 * a[1] + 10 * a[2] + a[3];
}
int soict()
{
	return 10000 * a[2]+1000*a[4]+ 100* a[5] + 10*a[6] + a[3];   
}
int x[10] = {0}; 
void Try(int k)
{
	for(int i = 0 ; i <= 9 ; i++)
	{
		if(x[i] == 0)
		{
			a[k] = i ; 
			x[i] = 1 ; 
			if(k == 6)
			{
				if((hust()+soict())==n && a[0] != 0 && a[2]!= 0)
				 sum += 1 ; 
			}
			else
			{
				Try(k+1);
			}
			x[i] = 0 ; 
		}
	}
}
int main ()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t ; 
	cin >> t ; 
	while(t--)
	{
		cin >> n ; 
	    Try(0);
	    cout << sum << "\n"; 
	    sum = 0 ; 
	}
	
	return 0 ; 
}





















