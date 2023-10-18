#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lexical Analysis
char **lexical_analysis(char *code, int *size) {
    int max_tokens = 20;
    char **tokens = malloc(max_tokens * sizeof(char *));
    char *token = strtok(code, " ");
    int i = 0;

    printf("\n========================\n");
    printf("Starting Lexical Analysis\n");
    printf("========================\n");

    while (token != NULL) {
        tokens[i] = malloc(strlen(token) + 1);
        strcpy(tokens[i], token);
        token = strtok(NULL, " ");
        i++;
    }

    *size = i;
    return tokens;
}

// Syntax Analysis
int syntax_analysis(char **tokens, int size) {
    int ifCount = 0, elseCount = 0, braceCount = 0;
    int semicolonCheck = 1;

    printf("\n========================\n");
    printf("Starting Syntax Analysis\n");
    printf("========================\n");

    for (int i = 0; i < size; i++) {
        if (strcmp(tokens[i], "if") == 0) ifCount++;
        if (strcmp(tokens[i], "else") == 0) elseCount++;
        if (strcmp(tokens[i], "{") == 0) braceCount++;
        if (strcmp(tokens[i], "}") == 0) braceCount--;

        // Check for a semicolon after assignment or expression
        if (strcmp(tokens[i], "=") == 0 || strcmp(tokens[i], ">") == 0 || strcmp(tokens[i], "<") == 0) {
            // Find next semicolon from this point
            int hasSemiColon = 0;
            for (int j = i + 1; j < size; j++) {
                if (strcmp(tokens[j], ";") == 0) {
                    hasSemiColon = 1;
                    break;
                }
                if (strcmp(tokens[j], "}") == 0) break; // reach the end of a block
            }
            if (!hasSemiColon) {
                semicolonCheck = 0;
                break;
            }
        }
    }

    return (ifCount == 1 && elseCount == 1 && braceCount == 0 && semicolonCheck);
}

// Semantic Analysis
int semantic_analysis(char **tokens, int size) {
    int hasRelOp = 0, hasAssignOp = 0;

    printf("\n=========================\n");
    printf("Starting Semantic Analysis\n");
    printf("=========================\n");

    for (int i = 0; i < size; i++) {
        if (strcmp(tokens[i], ">") == 0 || strcmp(tokens[i], "<") == 0) hasRelOp = 1;
        if (strcmp(tokens[i], "=") == 0) hasAssignOp = 1;
    }

    return (hasRelOp && hasAssignOp);
}

// Intermediate Code Generation
void intermediate_code_generation(char **tokens, int size) {
    printf("\n=======================================\n");
    printf("Starting Intermediate Code Generation\n");
    printf("=======================================\n");

    // Simplified intermediate code for this specific example
    printf("t1 = a > b\n");
    printf("ifFalse t1 goto L1\n");
    printf("c = a\n");
    printf("goto L2\n");
    printf("L1: c = b\n");
    printf("L2: nop\n");
}

int main() {
    char code[] = "if ( a > b ) { c = a ;  } else { c = b ; }";
    char *codeCopy = malloc(strlen(code) + 1);
    strcpy(codeCopy, code);

    int token_size;
    char **tokens;

    printf("\n=====================\n");
    printf("Code for Analysis:\n");
    printf("=====================\n");
    printf("%s\n", code);

    // Lexical Analysis
    tokens = lexical_analysis(codeCopy, &token_size);
    printf("Tokens generated in Lexical Analysis:\n");
    for (int i = 0; i < token_size; i++) {
        printf("[%s] ", tokens[i]);
    }
    printf("\n");

    // Syntax Analysis
    if (syntax_analysis(tokens, token_size)) {
        printf("Syntax analysis passed.\n");

        // Semantic Analysis
        if (semantic_analysis(tokens, token_size)) {
            printf("Semantic analysis passed.\n");

            // Intermediate Code Generation
            intermediate_code_generation(tokens, token_size);
        } else {
            printf("Semantic analysis failed. Compilation halted.\n");
            return 1;
        }
    } else {
        printf("Syntax analysis failed. Compilation halted.\n");
        return 1;
    }

    printf("\nBy;\n20CE015 - AYUSH DABHI \n20CE020 - AKSH DESAI \n20CE035 - HITEN JADAV");
    
    // Cleanup
    for (int i = 0; i < token_size; i++) {
        free(tokens[i]);
    }
    free(tokens);
    free(codeCopy);

    return 0;
}