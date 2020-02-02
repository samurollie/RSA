#ifndef NUMBERS_H
#define NUMBERS_H

#include <bits/stdc++.h>

typedef long long int lli;

/** @param n:   O número que se deseja saber se é primo.
 * @return:     Se o número é primo ou não. 
*/
int is_prime (int n);

/** @param */
int mdc (int a, int b);
int expoentes(int exp, int x);
int read_prime();
lli exponetiation (lli base, lli exp, lli mod);
int *extendedEuclid (int a, int b);

#endif