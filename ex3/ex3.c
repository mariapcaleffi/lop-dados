#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL,"");
    FILE *entrada, *saida;
    char caractere;

    entrada = fopen("ex3_r.txt", "r"); 
    saida = fopen("ex3_w.txt", "w"); 

    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir os arquivos.");
        return 1;
    }

    while ((caractere = fgetc(entrada)) != EOF) { 
        if (caractere == ' ' || caractere == '\n') { 
            continue; 
        } else {
            fputc(caractere, saida); 
        }
    }

    fclose(entrada); 
    fclose(saida); 

    printf("Espaços e quebras de linha removidos com sucesso.\n");

    return 0;
}
