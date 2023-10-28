#include <stdio.h>

void factorize(long long int number) {
    long int factor1 = 2;
    long int factor2;

    while (number % factor1) {
        if (factor1 <= number) {
            factor1++;
        } else {
            return;
        }
    }

    factor2 = number / factor1;
    printf("%lld = %ld * %ld\n", number, factor2, factor1);
}

int main() {
    long long int num = 239809320265259;
    factorize(num);
    return 0;
}

