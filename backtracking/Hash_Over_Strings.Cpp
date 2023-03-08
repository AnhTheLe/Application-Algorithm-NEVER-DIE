#include<bits/stdc++.h>
using namespace std;
const int MAX = 200 ;
int n,m;
string s[100] ;

void input(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i< n; i++){
        cin >> s[i];
    }
}

int Hash(string s, int i){
    // int result = (s[i]*pow(256, s.length() - i - 1 ));
    if(i = 0) return s[0]*pow(256, s.length() - 1 ) ;
    else return Hash(s,i-1) + Hash(s,i-2);
}

int Hash_over_Strings(string s){
    return Hash(s,s.length()) % m;
    // int result = 0;
    // for (int i = 0; i < s.length(); i++){
    //     result += (s[i]*pow(256, s.length() - i - 1 )); 
    // }
    // return result % m ;
}

int main(){
    input();
    for(int i = 0; i < n; i++){
        cout << Hash_over_Strings(s[i]);
        cout << endl;
    }
    
    return 0;
}
