#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
    if (n==1) return 0;
    if (n==2) return 1;
	int fib_pre_pre = 0;
    int fib_pre = 1;
    int fib_cur = 0;
    for (int i=2; i<n; ++i) {
            fib_cur = fib_pre_pre + fib_pre;
            fib_pre_pre = fib_pre;
            fib_pre = fib_cur;
    }
    return fib_cur;
}
// 0 1 1 2 3 5 8 13
int main() {
    cout << fib(7);
    return 0;
}