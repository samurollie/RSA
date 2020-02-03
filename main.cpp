#include <bits/stdc++.h>
#include "numbers/numbers.h"

using namespace std;

FILE* get_file(string msg) {
    FILE *arq;
    while (1) {
        cout << msg;
        char file[100];
        cin >> file;
        arq = fopen(file, "r");
        if (arq == NULL) {
            printf ("Arquivo não encontrado!\n");
        } else {
            break;
        }
    }
    return arq;
}

void generate_key() {
    lli p, q, e;
    printf("Digite um número primo (p): ");
    p = read_prime();

    printf("Digite um número primo diferente do anterior (q): ");
    q = read_prime();

    lli x = (p - 1) * (q - 1);
    printf("φ(n) = (p - 1) * (q - 1)\n");
    printf("φ(n) = %lld\n", x);
    
    while (1) {
        printf("Escolha um valor para 'e' dentro do seguinte intervalo: (1 < e < %lld)\n", x);
        cin >> e;
        if(e > 1 && e < x && mdc(e, x) == 1) {
            break;
        } else {
            cout << "Valor de 'e' invalido\n";
        }
    }
    
    cout << "\nGerando chave, por favor aguarde...\n"; 
    lli n = p * q;

    FILE *arq;
    arq = fopen("key.txt", "w");
    if (arq == NULL) {
        printf("Não foi possivel gerar a chave! (Não há espaço suficiente)\n");
        return;
    }

    fprintf (arq, "%lld %lld", e, n);
    cout << "Chave gerada!\n";
}

void encript () {
    while (1) {
        printf(" __________________________________________________\n");
        printf("|Selecione uma opção:                              |\n");
        printf("|                                                  |\n");
        printf("| 1 | - Inserir a mensagem de um arquivo de texto  |\n");
        printf("| 2 | - Inserir pelo terminal                      |\n");
        printf("|__________________________________________________|\n");
        int op;
        cin >> op;
        
        if (op == 1) {
            FILE *arch = get_file("\nDigite o nome do arquivo:\n");
            FILE *arq = get_file("\nInsira o arquivo que contém a chave:\n");

            lli e, n;
            fscanf(arq, "%lld %lld", &e, &n);

            FILE *crip = fopen("cript.txt", "w");
            
            cout << "Criptografando a mensagem!\n\n";
            char caracter;
            while (fscanf(arch, "%c", &caracter) != EOF) {
                lli base;
                if (caracter == ' ') {
                    base = 28;
                } else {
                    base = caracter - 63;
                }
                lli x = exponetiation(base, e, n);
                
                fprintf(crip, "%lld ", x);
            }
            cout << "Mensagem criptografada!\n\n";
            return;
        } else if (op == 2) {
            printf ("\nDigite a mensagem de texto para criptografar:\n");
            string texto;
            cin.ignore();
            getline(cin, texto);
            
            FILE *arq = get_file("\nInsira o arquivo que contém a chave: \n");    
            lli e, n;
            fscanf(arq, "%lld %lld", &e, &n);

            FILE *crip = fopen("cript.txt", "w");

            cout << "Criptografando a mensagem!\n\n";
            for (lli i = 0; i < texto.size(); i++) {
                lli base;
                if (texto[i] == ' ') {
                    base = 28;
                } else {
                    base = texto[i] - 63;
                }
                lli x = exponetiation(base, e, n);
                
                fprintf(crip, "%lld ", x);
            }
            cout << "Mensagem criptografada!\n\n";
            return;
        } else {
            printf("Opção inválida!\n");
        }
    }
}

void desencript() {
    lli p, q, e;
    printf("Digite um número primo (p): ");
    p = read_prime();

    printf("Digite um número primo diferente do anterior (q): ");
    q = read_prime();

    lli x = (p - 1) * (q - 1);
    printf("φ(n) = (p - 1) * (q - 1)\n");
    printf("φ(n) = %lld\n", x);
    
    while (1) { // Loop infinito
        printf("Escolha um valor para 'e' dentro do seguinte intervalo: (1 < e < %lld)\n", x);
        cin >> e;
        if(e > 1 && e < x && mdc(e, x) == 1) {
            break;
        } else {
            cout << "Valor de 'e' invalido!\n";
        }
    }
    lli *d = extendedEuclid(e, x);
    lli n = p * q;

    FILE *archive = get_file("\nInsira o arquivo com a mensagem criptografada:\n");

    FILE *desencript = fopen("desencript.txt", "w");

    lli num;
    if (d[1] < 0) {
        d[1] += x;
    }

    cout << "\nDescriptando o texto...\n";
    while(fscanf(archive, "%lld", &num) != EOF) {
        lli result = exponetiation(num, d[1], n);
        char caracter;
        if (result == 28) {
            caracter = ' ';
        } else {
            caracter = result + 63;
        }
        fprintf(desencript, "%c", caracter);
    }
    cout << "\nTexto descriptografado!\n";
}

int main() {
    system("clear");
    while (1) {
        lli op;
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