#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ "teste.txt"

int main(int argc, char *argv[]) {
  FILE *file;
  
  if (argc != 2) {
    printf("Uso: %s <nome>\n", argv[0]);
  }

  file = fopen(ARQ, "r");
  if (file == NULL) {
    printf("Erro ao abrir arquivo.\n");
  }

  char *linha = NULL;
  size_t tamanho =  0;
  ssize_t lida;

  while ((lida = getline(&linha, &tamanho, file)) != -1){ 
    if (linha[lida - 1] == '\n') {
      linha[lida - 1] = '\0';
    }
    
    if (strcmp(linha, argv[1]) == 0) {
      printf("Senha correta.\n");
      break;
    } else {
      printf("Senha incorreta.\n");
      break;
    }
  }

  free(linha);
  fclose(file); 

  return 0;
}
