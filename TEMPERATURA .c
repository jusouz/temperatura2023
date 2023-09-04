#include <stdio.h>

int main() {
    int Dias,i;
    printf("Digite o numero de dias do mes: ");
    scanf("%d", &Dias);

    int temperaturas[Dias][2];
    FILE *file = fopen("dados.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (i = 0; i <Dias; i++) {
        fscanf(file, "%d %d", &temperaturas[i][0], &temperaturas[i][1]);
    }

    fclose(file);
    
   int Escolha;
    do {
        printf("\nMenu:\n");
        printf("1. Temperatura media maxima do mes.\n");
        printf("2. Temperatura media minima do mes.\n");
        printf("3. Dia com a maior amplitude termica.\n");
        printf("4. Numero de dias com temperatura minima abaixo de um determinado limiar.\n");
        printf("0. Sair.\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &Escolha);

        switch (Escolha) {
            case 1: {
                double maxMedia = 0;
                for ( i = 0; i < Dias; i++) {
                    maxMedia += temperaturas[i][0];
                }
                maxMedia/= Dias;
                printf("Temperatura media maxima do mes: %.2lf\n", maxMedia);
                break;
            }
            case 2: {
                double minMedia= 0;
                for ( i = 0; i < Dias; i++) {
                    minMedia += temperaturas[i][1];
                }
                minMedia /= Dias;
                printf("Temperatura media minima do mes: %.2lf\n", minMedia);
                break;
            }
            case 3: {
                int maxSoma = 0;
                int maxDia = -1;
                for ( i = 0; i < Dias; i++) {
                    int max = temperaturas[i][0];
                    int min = temperaturas[i][1];
                    if (max - min > maxSoma) {
                        maxSoma = max - min;
                        maxDia = i + 1;
                    }
                }
                printf("Dia com a maior amplitude termica: Dia %d (Amplitude: %dC)\n", maxDia, maxSoma);
                break;
            }
            case 4: {
                int belowThreshold = 0;
                int limite;
                printf("Digite o limiar de temperatura minima: ");
                scanf("%d", &limite);
                for ( i = 0; i < Dias; i++) {
                    if (temperaturas[i][1] <limite) {
                        belowThreshold++;
                    }
                }
                printf("Numero de dias com temperatura minima abaixo de %d C: %d\n", limite, belowThreshold);
                break;
            }
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (Escolha != 0);

    return 0;
} 



    
