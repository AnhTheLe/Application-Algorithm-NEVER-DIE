#include<bits/stdc++.h>
using namespace std ;

int n , k ;
double Max = -1e7;  

int a[100001]; 

int main()
{
	cin >> n >> k ; 
	for(int i = 1 ; i <= n ; i++)
	   cin >> a[i]; 
	for(int i = 1 ; i <= n ;i++)
	{
		double sum = 0 ;  
		for(int j = i  ; j >= 1 ; j--)
		{
			sum += a[j]; 
		    if(i - j >= k - 1)
			{
				Max = max(Max,sum * 1.0 / (i - j + 1) ) ;  
			}	
		} 
	} 
	printf("%.5lf", Max) ;  
	return 0 ;  
} 
