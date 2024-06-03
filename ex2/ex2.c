#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");
    FILE *entrada, *saida;
    char caractere, proximo;

    entrada = fopen("ola.txt", "r"); // Abre o arquivo de entrada
    saida = fopen("ola2.txt", "w"); // Abre o arquivo de sa�da

    if (entrada == NULL || saida == NULL) { // Verifica se houve erro na abertura dos arquivos
        printf("Erro ao abrir os arquivos.");
        return 1;
    }

    while ((caractere = fgetc(entrada)) != EOF) { // L� caractere por caractere at� o fim do arquivo
        if (caractere == '/') { // Verifica se � o in�cio de um coment�rio
            proximo = fgetc(entrada);
            if (proximo == '/') { // Coment�rio de linha
                while ((caractere = fgetc(entrada)) != '\n' && caractere != EOF); // Ignora at� o final da linha
            } else if (proximo == '*') { // Coment�rio de bloco
                do { // Ignora at� encontrar o fim do coment�rio de bloco
                    while ((caractere = fgetc(entrada)) != '*');
                } while ((caractere = fgetc(entrada)) != '/');
            } else {
                fputc(caractere, saida); // Se n�o for coment�rio, escreve no arquivo de sa�da
                fputc(proximo, saida);
            }
        } else {
            fputc(caractere, saida); // Se n�o for coment�rio, escreve no arquivo de sa�da
        }
    }

    fclose(entrada); // Fecha o arquivo de entrada
    fclose(saida); // Fecha o arquivo de sa�da

    printf("Coment�rios removidos com sucesso.\n");

    return 0;
}
