#include <stdio.h>

int fibo(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibo(n-1) + fibo(n-2);
}

void printFiboSeries(int i, int n) {
    if (i > n)      // stop condition
        return;

    printf("%d ", fibo(i));  // print current Fibonacci

    printFiboSeries(i + 1, n);  // recursive call for next number
}

int main() {
    int n;
    printf("Enter how many Fibonacci numbers you want: ");
    scanf("%d", &n);

    printFiboSeries(0, n - 1);

    return 0;
}
