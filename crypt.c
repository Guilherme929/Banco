#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>  // Novo cabeçalho para operações de criptografia no OpenSSL 3.0

void gerar_hash(char *input) {
    unsigned char hash[EVP_MAX_MD_SIZE];  // Usamos EVP_MAX_MD_SIZE para o tamanho máximo do hash
    unsigned int hash_len = 0;

    // Criamos um contexto de hash com a nova API
    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();

    if (mdctx == NULL) {
        printf("Erro ao criar contexto de hash.\n");
        return;
    }

    // Inicializa o contexto de hash para SHA-256
    if (EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL) != 1) {
        printf("Erro ao inicializar o hash.\n");
        EVP_MD_CTX_free(mdctx);
        return;
    }

    // Atualiza o contexto com os dados
    if (EVP_DigestUpdate(mdctx, input, strlen(input)) != 1) {
        printf("Erro ao atualizar o hash.\n");
        EVP_MD_CTX_free(mdctx);
        return;
    }

    // Finaliza o cálculo do hash
    if (EVP_DigestFinal_ex(mdctx, hash, &hash_len) != 1) {
        printf("Erro ao finalizar o hash.\n");
        EVP_MD_CTX_free(mdctx);
        return;
    }

    // Exibe o hash gerado
    printf("SHA-256 Hash: ");
    for (unsigned int i = 0; i < hash_len; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    // Libera o contexto do hash
    EVP_MD_CTX_free(mdctx);
}

int main(int argc, char *argv[]) {
    char *senha = argv[1];
    if (argc != 2) {
      printf("Uso: %s <texto>\n", argv[0]);
    }
    gerar_hash(senha);
    return 0;
}

