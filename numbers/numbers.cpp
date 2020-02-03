
#include "numbers.h"

lli is_prime (lli n) { 
    if (n == 0 || n == 1) return 0;
    for (lli i = 2; i <= sqrt(n); i++) {
        if (!(n % i)) {
            return 0;
        }
    }
    return 1;
}

lli mdc (lli a, lli b) {
    return (b == 0) ? a : mdc(b, a % b);
}

lli expoentes(lli exp, lli x) {
    lli maior = 0; // sempre pegamos o maior primo entre os dois.
    for (lli i = 2; i <= x; i++) {
        if ((i * exp) % x == 1) {
            maior = i;
        }
    }
    return maior;
}

lli read_prime() {   
    lli flag = 1;
    lli n;
    do {
        scanf("%lld", &n);
        if (is_prime(n) == 1) {
            printf ("O número escolhido é primo.\n\n");
            flag = 0;
        } else {
            printf ("O número digitado não é primo. Tente novamente.\n\n");
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

lli *extendedEuclid (lli a, lli b) {
	lli *dxy = (lli*) malloc(sizeof(lli) * 3);

	if (b == 0){
		dxy[0] = a; 
        dxy[1] = 1; 
        dxy[2] = 0;
		return dxy;
	} else {
		lli t, t2; // variaveis auxiliar.
		dxy = extendedEuclid(b, a % b);
		
        t = dxy[1];
		t2 = dxy[2];
		
        dxy[1] = dxy[2];
		dxy[2] = t - a/b * t2;
		return dxy;
	}
}