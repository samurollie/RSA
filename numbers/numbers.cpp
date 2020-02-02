
#include "numbers.h"

int is_prime (int n) { 
    if (n == 0 || n == 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (!(n % i)) {
            return 0;
        }
    }
    return 1;
}

int mdc (int a, int b) {
    return (b == 0) ? a : mdc(b, a % b);
}

int expoentes(int exp, int x) {
    int maior = 0;
    for (int i = 0; i <= x; i++) {
        if ((i * exp) % x == 1) {
            maior = i;
        }
    }
    return maior;
}

int read_prime() {   
    int flag = 1;
    int n;
    do {
        scanf("%d", &n);
        if (is_prime(n) == 1) {
            printf ("O número escolhido é primo.\n");
            flag = 0;
        } else {
            printf ("O número digitado não é primo. Tente novamente.\n");
        }
    } while (flag);
    return n;
}

lli exponetiation (lli base, lli exp, lli mod) {
    lli r = 1;
    while (exp) {
        if (exp & 1) {
            r = (r * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp >> 1;
    }
    return r;
}

int *extendedEuclid (int a, int b) {
	int *dxy = (int*) malloc(sizeof(int) * 3);

	if (b == 0){
		dxy[0] = a; 
        dxy[1] = 1; 
        dxy[2] = 0;
		return dxy;
	} else {
		int t, t2;
		dxy = extendedEuclid(b, a % b);
		
        t = dxy[1];
		t2 = dxy[2];
		
        dxy[1] = dxy[2];
		dxy[2] = t - a/b * t2;
		return dxy;
	}
}