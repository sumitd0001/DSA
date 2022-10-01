#include <bits/stdc++.h>
using namespace std;

//Recursion
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

//Dynamic Programming
int fib_dp(int n) {
    if (n==0) return 0;
    int a{0};
    int b{1};
    int c{0};
     for(int i = 2; i<=n; ++i) {
        c = a+b;
        a = b;
        b = c;
     }
     return b;
}

int main () {

    int n{0};
    cin>>n;
    cout<<"Fibonaaci Recursion (" << n << ") : " << fib(n)<<"\n";
    cout<<"Fibonaaci DP (" << n << ") : " << fib_dp(n)<<"\n";
    return 0;
}