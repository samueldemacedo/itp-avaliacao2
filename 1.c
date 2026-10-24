#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

void linhas();
void calcular_medias(float notas[][3], float *medias, int qtd);
void exibir_boletim(char nomes[][50], float notas[][3], float *medias, int qtd);

int main(){
    int qtd_alunos;

    linhas();
    printf("BOLETIM DA TURMA\n");
    linhas();

    do {
        printf("Insira a quantidade de alunos da turma (1 a 10): ");
        scanf("%d", &qtd_alunos);
        if(qtd_alunos < 1 || qtd_alunos > 10){
            printf("Quantidade invalida! Tente novamente.\n");
        }
    } while(qtd_alunos < 1 || qtd_alunos > 10);

    getchar(); 

    float *medias = (float *) malloc(qtd_alunos * sizeof(float));
    
    if(medias == NULL){
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    char nomes[10][50];
    float notas[10][3];

    for(int i = 0; i < qtd_alunos; i++){
        printf("\n");
        linhas();
        
        do {
            printf("Insira o nome do %d° aluno: ", i+1);
            fgets(nomes[i], 50, stdin);
            nomes[i][strcspn(nomes[i], "\n")] = '\0';
        } while(strlen(nomes[i]) == 0);

        for(int j = 0; j < 3; j++){
            do {
                printf("Insira a %d° nota (0 a 10): ", j+1);
                scanf("%f", &notas[i][j]);
                if(notas[i][j] < 0 || notas[i][j] > 10){
                    printf("Nota invalida! Deve ser entre 0 e 10.\n");
                }
            } while(notas[i][j] < 0 || notas[i][j] > 10);
        }
        getchar();
    }

    calcular_medias(notas, medias, qtd_alunos);

    exibir_boletim(nomes, notas, medias, qtd_alunos);

    float soma_geral = 0;
    float maior_media = -1;

    for(int i = 0; i < qtd_alunos; i++){
        soma_geral += medias[i];
        if(medias[i] > maior_media){
            maior_media = medias[i];
        }
    }

    printf("\nMedia GERAL da turma: %.2f\n", soma_geral / qtd_alunos);
    
    printf("Maior media (%.2f) obtida por: ", maior_media);
    for(int i = 0; i < qtd_alunos; i++){
        if(medias[i] == maior_media){
            printf("[%s] ", nomes[i]);
        }
    }
    printf("\n");
    linhas();

    free(medias);

    return 0;
}


void linhas(){
    printf("----------------------------------------------------\n");
}

void calcular_medias(float notas[][3], float *medias, int qtd){
    for(int i = 0; i < qtd; i++){
        medias[i] = (notas[i][0] + notas[i][1] + notas[i][2]) / 3.0; 
    }
}

void exibir_boletim(char nomes[][50], float notas[][3], float *medias, int qtd){
    printf("\n\n");
    linhas();
    printf("NOME\t\tN1\tN2\tN3\tMEDIA\tSITUACAO\n");
    linhas();
    
    for(int i = 0; i < qtd; i++){
        printf("%s\t\t%.1f\t%.1f\t%.1f\t%.2f\t", nomes[i], notas[i][0], notas[i][1], notas[i][2], medias[i]);
        
        if(medias[i] >= 6.0){
            printf("[Atingiu a meta]\n");
        } else {
            printf("[Abaixo da meta]\n");
        }
    }
}