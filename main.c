#include <string.h>
#include <stdio.h>
#include "include/utils.h"

#define teste "teste.txt"

int sleiwecoin() {
  FILE  *file;
  char c;

  file = fopen(".asci.txt", "r");
  if (file == NULL) {
    printf("[!] não foi possível abrir o arquivo.\n");
    return 1;
  }

  while ((c = fgetc(file)) != EOF) {
    putchar(c);
  }
  fclose(file);
}


char saldo() {
  FILE *file;
  char c;  

  file = fopen(".saldo.txt", "r");
  if (file == NULL) {
    printf("[!] não foi possível veerificar o salvo.\n");
    return -1;
  }

  while ((c = fgetc(file)) != EOF) {
    putchar(c);
  } 
  fclose(file);
}

int help() {
  FILE *file;
  char c;

  file = fopen(".teste.txt", "r");
  if (file == NULL) {
    printf("[-] não foi possível encontrar o help.\n");
    printf("Por favor reinstale o programa novamente.\n");
    return 1;
  }

  while ((c = fgetc(file)) != EOF) {
    putchar(c);
  }
  fclose(file);
}


int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Uso: %s [argumento] <nome arquivo>\n", argv[0]);
    return 1;
  }
  
  if (strcmp(argv[1], "-ascii") == 0) {
    sleiwecoin();
  }
  
  for (int i = 1; i < argc; i++) {
    if (strstr(argv[i], "-h") != NULL) {
      help();
      return 0;
    }
  }

  if (strcmp(argv[1], "-w") == 0) {
    printf("[+] escrevendo\n"); 
  } else if (strcmp(argv[1], "-s") == 0){
    printf("Saldo: %s\n");
  } else if (strcmp(argv[1], "-a") == 0) {
    criar_users(argv[2], argv[3], argv[4]);    
  } else {
    printf("Erro: -h\n");
  }
  return 0;
}
