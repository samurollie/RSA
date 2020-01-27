#include <bits/stdc++.h>

using namespace std;

int is_prime (int n) { // Verifica se um numero e primo
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
        if (x % ((i * exp) - 1) == 0) {
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

void generate_key() {
    int p, q, d;
    printf("Digite um número primo: ");
    p = read_prime();

    printf("Digite outro número primo: ");
    q = read_prime();

    printf ("Escolha um número para o expoente: \n");
    scanf ("%d", &d);
    int x = (p - 1) * (q - 1);
    int e = expoentes(d, x);
    int n = p * q;

    FILE *arq;
    arq = fopen("key.txt", "w");
    
    fprintf (arq, "%d %d", e, n);
}

void encript () {
    printf ("Digite a mensagem de texto para criptografia:\n");
    string texto;
    cin.ignore(); // getchar();
    getline(cin, texto); //fgets();
    
    printf ("Insira o arquivo que contém a chave: \n");
    char file[100];
    cin >> file;
    FILE *arq = fopen(file, "r");
    if (arq == NULL) {
        printf ("Arquivo não encontrado.\n");
        return;
    }

    int e, n;
    fscanf(arq, "%d %d", &e, &n);
    printf("e = %d, n = %d\n", e, n);

    FILE *crip = fopen("cript.txt", "w");
    for (int i = 0; i < texto.size(); i++) {
        if (texto[i] == ' ') {
            unsigned long long int x = 28;
            for(int j = 0; j < e; j++) {
                x *= 28;
            }
            fprintf(crip, "%lld ", x % n);
        } else {
            int h = texto[i] - 63;
            printf ("%c = %d\n", texto[i], h);
            unsigned long long int x = h;
            for(int j = 1; j < e; j++) {
                printf("x = %lld\n", x);
                x *= h;
            }
            printf ("x = %lld\n", x);
            fprintf(crip, "%lld ", x % n);
        }
    }
}

int main() {
    int op;
    printf ("Selecione uma opção:\n");
    printf ("(1) - Gerar a chave\n(2) - Encriptar\n(3) - Desencriptar\n(4) - Sair\n");
    scanf("%d", &op);
    switch (op) {
        case 1:
            generate_key();
            break;

        case 2:
            encript();
            break;

        case 3:
            // desencript();
            break;
    }
}