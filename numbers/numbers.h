#ifndef NUMBERS_H
#define NUMBERS_H

#include <bits/stdc++.h>

typedef long long int lli;

/** @param n:   O número que se deseja saber se é primo.
 *  @return:    Se o número é primo ou não. 
 * */
lli is_prime (lli n);

/** @param a:   Primeiro parâmetro para o cálculo do MDC
 *  @param b:   Outro parâmetro para o cálculo do MDC 
 *  @return:    O MDC entre 'a' e 'b'
 * */
lli mdc (lli a, lli b);

/** @return:    Retorna o valor lido, caso ele seja primo. 
 * */
lli read_prime(); 

/** @param  base:   Base da potenciação.
 *  @param  exp:    Expoente da potenciação.
 *  @param  mod:    O número que se deseja calcular o mod. / < pessimo// pessimo nada
 *  @return:        Resultado final da exponenciação modular rápida.
 * */
lli exponetiation (lli base, lli exp, lli mod); //This is the end?????

/** @param  a:  é o numero relativamente primo a b.  
 *  @param  b:  é (p - 1) * (q - 1); 
 *  @return:    Resultado final do algoritmo de Euclides extendido;
  */
lli *extendedEuclid (lli a, lli b);

#endif