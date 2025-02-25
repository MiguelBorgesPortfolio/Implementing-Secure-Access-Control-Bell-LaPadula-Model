#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define ALLOWED_DIR "/dados/medio_grupo_04_65_52"
#define WHITELIST_SIZE 1

// Lista de arquivos permitidos (whitelist)
const char *whitelist[] = {
    "intermediario_04_65_52.txt" 
};

// Função para verificar se o arquivo está na whitelist
int is_in_whitelist(const char *filename) {
    for (int i = 0; i < WHITELIST_SIZE; i++) {
        if (strcmp(filename, whitelist[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Função para verificar path traversal
int is_path_traversal(const char *path) {
    return strstr(path, "../") != NULL;
}

int main(int argc, char *argv[]) {

    char filepath[512];
    struct stat file_stat;

    // Extrair apenas o nome do arquivo
    char *filename = strrchr(argv[1], '/');
    filename = filename ? filename + 1 : argv[1];

    // Verificar se o arquivo está na whitelist
    if (!is_in_whitelist(filename)) {
        fprintf(stderr, "Acesso negado: Arquivo não autorizado.\n");
        return 1;
    }

    // Verificar se há tentativas de path traversal
    if (is_path_traversal(argv[1])) {
        fprintf(stderr, "Acesso negado: Tentativa de path traversal detectada.\n");
        return 1;
    }

    // Construir o caminho completo
    snprintf(filepath, sizeof(filepath), "%s/%s", ALLOWED_DIR, filename);

    // Verificar se o arquivo existe e é um arquivo regular
    if (stat(filepath, &file_stat) != 0 || !S_ISREG(file_stat.st_mode)) {
        fprintf(stderr, "Erro: Arquivo não encontrado ou inválido.\n");
        return 1;
    }

    // Abrir e exibir o conteúdo do arquivo
    FILE *file = fopen(filepath, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}
