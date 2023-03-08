#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
int N;
int x[MAX];
int counts = 0;
int solve(){

    int hust = 1000 * x[0] + 100 * x[1] + 10 * x[2] + x[3];
    int soict = 10000 * x[2] + 1000 * x[4] + 100 * x[5] + 10 * x[6] + x[4];

    int sum = hust + soict;
    return sum;
}
void solution()
{
    int sum = solve();
    if (sum == N)
        counts++;
}

// bool check(int v, int k)
// {
//     for (int i = 1; i < k; i++)
//     {
//         if (x[i] == v)
//             return false;
//     }
//     return true;
// }
int a[10] = {0};
void TRY(int k)
{
    for (int v = 0; v <= 9; v++)
    {
        if(a[k] == 0)
		{
            a[k] = 1;
			x[k] = v;
			if(k == 6)
			{
				if(solve() == N && x[0] != 0 && x[2]!= 0)
				  counts+=1;
			}
			else
			{
				TRY(k+1);
			}
			a[k] = 0 ;
		}
    }
}

int main()
{
    int n;
    cin >> n;
    
	while(n--)
	{
		cin >> N ; 
	    TRY(0);
	    cout << counts << "\n"; 
	    counts = 0 ; 
	}

}
