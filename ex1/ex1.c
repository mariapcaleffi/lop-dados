#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

void abrir(){
	setlocale(LC_ALL,"");
	char numeros[30];
	FILE* arquivo1 = fopen("arq1.csv", "r");
	FILE* arquivo2 = fopen("arq2.csv", "r");
	FILE* arquivomesc = fopen("arq_mesc.csv", "w");
	
	if (arquivo1 == NULL || arquivo2 == NULL || arquivomesc == NULL) {
        printf("Erro ao abrir os arquivos\n");
        return 1;
    }
    
    while((fgets(numeros, 30, arquivo1)) != NULL){
    	fputs(numeros, arquivomesc);
	}
	while((fgets(numeros, 30, arquivo2)) != NULL){
		fputs(numeros, arquivomesc);
	}
	fclose(arquivo1);
	fclose(arquivo2);
	fclose(arquivomesc);

}

int main(){
	setlocale(LC_ALL,"");
	abrir();
	FILE* arquivocompleto = fopen("arq_mesc.csv", "r");
	char caracteres[30];
	while(fgets(caracteres, 30, arquivocompleto)){
		printf("%s", caracteres);
	}
	return 0;
}
