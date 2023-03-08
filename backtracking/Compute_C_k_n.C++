#include<iostream>
using namespace std;
int n;
int A[100];
void print(){

}

void Try(int k){
    for(int i=0;i< n;i++){
        A[k] = A[k]*(n-i);
        if(k == n-1) print();
        else Try(k+1);
    }
}

int main(){
    cin >> n;
    Try(0);
}