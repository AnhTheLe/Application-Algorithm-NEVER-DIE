#include <iostream>
using namespace std;
int n;
int A[1000];
bool bMark[1000];
void print(){
    for(int i = 1; i<= n; i++){
        cout<< A[i] << " ";
    }
    cout<< "\n";
}
void Try(int k){
    for(int i=1; i<= n; i++)
    {
        if(!bMark[i]){
            A[k] = i;
            bMark[i] = true;
            if (k == n) print();
            else Try(k+1);
            bMark[i] = false;
        }
    }
}
int main(){

    cin >> n;
    Try(1);
}