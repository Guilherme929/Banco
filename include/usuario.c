#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int criar_users(const char *nome, const char *email, const char *senha) {
  FILE *file;
  const char *path = "data/users.txt";
  
  if (access("data", F_OK) == -1) {
    if (mkdir("data", 0700) == -1) {
      printf("[!] erro ao cria pasta\n");
      return 1;
    }
  }


  file = fopen(path, "a");
  if (file == NULL) {
    printf("[!] não foi possível salvar dados.\n");
    return 1;
  }

  fprintf(file, "%s|%s|%s\n", nome, email, senha);
  fclose(file);
}

int ler_users(const char *nome, const char *email, const char *senha) {
  FILE *file;
  const char *arq = ""  
 
  file = fopen() 
}
