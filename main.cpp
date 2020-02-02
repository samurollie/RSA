#include <bits/stdc++.h>
#include "numbers/numbers.h"

using namespace std;

void generate_key() {
    int p, q, d;
    printf("Digite um número primo: ");
    p = read_prime();

    printf("Digite outro número primo: ");
    q = read_prime();

    printf ("Escolha um número para o expoente: \n");
    scanf ("%d", &d);
    printf("\n");
    cout << "Gerando chave, por favor aguarde...\n";
    int x = (p - 1) * (q - 1);
    int e = expoentes(d, x);
    int n = p * q;

    FILE *arq;
    arq = fopen("key.txt", "w");
    if (arq == NULL) {
        printf("Não foi possivel gerar a chave! (Não há espaço suficiente)\n");
        return;
    }

    fprintf (arq, "%d %d", e, n);
    cout << "Chave gerada!\n";
}

void encript () {
    printf ("\nDigite a mensagem de texto para criptografia:\n");
    string texto;
    cin.ignore();
    getline(cin, texto);
    
    FILE *arq;
    while (1) {
        printf ("\nInsira o arquivo que contém a chave: \n");
        char file[100];
        cin >> file;
        arq = fopen(file, "r");
        if (arq == NULL) {
            printf ("Arquivo não encontrado!\n");
        } else {
            break;
        }
    }

    int e, n;
    fscanf(arq, "%d %d", &e, &n);

    FILE *crip = fopen("cript.txt", "w");
    for (int i = 0; i < texto.size(); i++) {
        lli base;
        if (texto[i] == ' ') {
            base = 28;
        } else {
            base = texto[i] - 63;
        }
        printf ("%c = %lld\n", texto[i], base);

        lli x = exponetiation(base, e, n);
        
        printf ("x = %lld\n", x);
        fprintf(crip, "%lld ", x);
    }
}

void desencript() {
    int p, q, a;
    printf("\nDigite um número primo: ");
    p = read_prime();

    printf("Digite outro número primo: ");
    q = read_prime();

    printf ("Escolha um número para o expoente: ");
    scanf ("%d", &a);
    int x = (p - 1) * (q - 1);
    int e = expoentes(a, x);
    int n = p * q;
    int *d = extendedEuclid(e, x);

    printf("\nInsira o arquivo com a mensagem criptografada: ");
    char file[250];
    scanf("%s", file); 

    FILE *archive = fopen(file, "r");
    if (archive == NULL) {
        cout << "Arquivo não encontrado!\n";
    }

    FILE *desencript = fopen("desencript.txt", "w");

    lli num;
    if (d[1] < 0) {
        d[1] += x;
    }
    while(fscanf(archive, "%lld", &num) != EOF) {
        lli result = exponetiation(num, d[1], n);
        printf("result = %lld\n", result);
        char caracter;
        if (result == 28) {
            caracter = ' ';
        } else {
            caracter = result + 63;
        }
        fprintf(desencript, "%c", caracter);
    }
}

int main() {
    system("clear");
    while (1) {
        int op;
        printf("____________________________________________________\n");
        printf("|                                                  |\n");
        printf("|           SISTEMA DE CRIPTOGRAFIA RSA            |\n");
        printf("|__________________________________________________|\n");
        printf("|Selecione uma opção:                              |\n");
        printf("|                                                  |\n");
        printf("| 1 | - Gerar a chave                              |\n");
        printf("| 2 | - Encriptar                                  |\n");
        printf("| 3 | - Desencriptar                               |\n");
        printf("| 4 | - Sair                                       |\n");
        printf("|__________________________________________________|\n");
        cin >> op;
        switch (op) {
            case 1:
                generate_key();
                return 0;
                break;

            case 2:
                encript();
                return 0;
                break;

            case 3:
                desencript();
                return 0;
                break;

            case 4:
                return 0;
                break;
            default:
                cout << "Opção inválida!\n";
                break;
        }
    }
}