#include<iostream>
using namespace std;
int n;
int A[100];
void print(){
    for(int i=0; i< n; i++){
        cout<< A[i];
    }
    cout<< "\n";
}

void Try(int k){
    for(int i = 0; i <= 1; i++){
        if(A[k-1] + i != 2){
            A[k] = i;
            if(k == n-1) print();
            else Try(k+1);
        }
        // A[k] = i;
        // if(k == n-1) print();
        // else Try(k+1);
    }
}

int main(){
    cin >> n;
    Try(0);
}