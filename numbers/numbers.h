#ifndef NUMBERS_H
#define NUMBERS_H

#include <bits/stdc++.h>

typedef long long int lli;

/** @param n:   O número que se deseja saber se é primo.
 * @return:     Se o número é primo ou não. 
*/
lli is_prime (lli n);

/** @param */
lli mdc (lli a, lli b);
lli expoentes(lli exp, lli x);
lli read_prime();
lli exponetiation (lli base, lli exp, lli mod);
lli *extendedEuclid (lli a, lli b);

#endif