#include <stdio.h>
#include <stdlib.h>

#define SHIFT 3

void encryptFile(FILE *inputFile, FILE *outputFile) {
    char ch;

    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + SHIFT) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + SHIFT) % 26;
        }
        fputc(ch, outputFile);
    }
}

int main() {
    FILE *inputFile, *outputFile;

    inputFile = fopen("Descriptografado.txt", "r");
    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    outputFile = fopen("Criptografado.txt", "w");
    if (outputFile == NULL) {
        printf("Erro ao criar o arquivo de saída.\n");
        return 1;
    }

    encryptFile(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    printf("Arquivo criptografado com sucesso.\n");

    return 0;
}
