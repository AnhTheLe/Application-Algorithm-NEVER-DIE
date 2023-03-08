#include<bits/stdc++.h>
using namespace std ;

int n , x ; 
string s ; 
deque<int> t ;  // t la ngan xep chua chuong 
deque<int> k ;  // k la ngan xep chua hanh lang 
int main ()
{
	cin >> n ;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> x;
		t.push_back(x);
	}
	cin >> s ; 
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i] == 'C')  // khi báo hieu o chuong 
		{
			if(!t.empty())
			{
				k.push_back(t.front());
				t.pop_front(); 
			} 
		}
		if(s[i] == 'H')
		{
			if(!k.empty())
			{
				t.push_front(k.front());
				k.pop_front(); 
			} 
		} 
	} 
	   
	for(int i = 0 ; i < t.size() ; i++)
	   cout << t[i] << " ";
	return 0 ;  
	   
}













