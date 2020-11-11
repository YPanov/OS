#include <stdio.h>
#include <stdlib.h>

int ril(int *avail, int *row, int n){
    for(int i = 0; i < n; ++i){
        if(row[i] > avail[i]){
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    FILE *input = fopen("input_ok.txt", "r");
    if (input == NULL) {
        perror("ERROR: Can't open file input.txt\n");
        return EXIT_FAILURE;
    }

    int R, P;
    fscanf(input, "%d %d", &R, &P);

    int *excist = malloc(sizeof(int) * R);
    if (excist == NULL) {
        perror("ERROR: Can't allocate memory\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < R; ++i) {
        fscanf(input, "%d", &excist[i]);
    }

    int *avail = malloc(sizeof(int) * R);
    if (avail == NULL) {
        perror("ERROR: Can't allocate memory\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < R; ++i) {
        fscanf(input, "%d", &avail[i]);
    }

    int **C = malloc(sizeof(int *) * P);
    if (C == NULL) {
        perror("ERROR: Can't allocate memory\n");
        return EXIT_FAILURE;
    }

    for (int p = 0; p < P; ++p) {
        C[p] = malloc(sizeof(int) * R);
        if (C[p] == NULL) {
            perror("ERROR: Can't allocate memory\n");
            return EXIT_FAILURE;
        }

        for(int r = 0; r < R; ++r) {
            fscanf(input, "%d", &C[p][r]);
        }
    }

    int **Req = malloc(sizeof(int *) * P);
    if (Req == NULL) {
        perror("ERROR: Can't allocate memory\n");
        return EXIT_FAILURE;
    }

    for (int p = 0; p < P; ++p) {
        Req[p] = malloc(sizeof(int) * R);
        if (Req[p] == NULL) {
            perror("ERROR: Can't allocate memory\n");
            return EXIT_FAILURE;
        }

        for(int r = 0; r < R; ++r) {
            fscanf(input, "%d", &Req[p][r]);
        }
    }
    fclose(input);

    int *finished = calloc(P, sizeof(int));
    for(int i = 0; i < P; ++i){
        for (int j = 0; j < P; ++j) {
            if (!finished[j] && ril(avail, Req[j], R)) {
                for (int r = 0; r < R; ++r) {
                    avail[r] += C[j][r];
                }
                finished[j] = 1;
                break;
            }
        }
    }

    int deadlocked = 0;
    for (int i = 0; i < P; ++i) {
        if (!finished[i]) {
            ++deadlocked;
        }
    }

    FILE *output = fopen("output_ok.txt", "w");
    if (deadlocked == 0) {
        fprintf(output, "no deadlock\n");
    } else {
        fprintf(output, "%d processes are in a deadlock\n", deadlocked);
    }
    fclose(output);
    free(excist);
    free(avail);
    for (int i = 0; i < P; ++i) {
        free(C[i]);
        free(Req[i]);
    }
    free(C);
    free(Req);
    free(finished);
    return EXIT_SUCCESS;
}
