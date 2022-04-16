/*
objetivo da Aula:

- Criar um programa para cadastrar até 100 alunos ;
- Cada aluno deve ter as seguintes informações:
        # nome
        # email (OPCIONAL)
        # matrícula
        # notas A1, A2 e A3
- Capacidade de excluir um aluno já cadastrado pela matrícula
- Listar os alunos cadstrados com nome, email e matrícula
- listar os alunos cadstrados com matrícula, nome, notas A1, A2 e A3, além da média final
- A média é conposta de A1 valendo 20% da nota final, A2 30% da nota final e A3 valendo 50% da nota final;
- Listar os alunos aprovados com matrícula, nome e média final. Aprovados tem média igual ou superior a 7;
- Listar os alunos reprovados com matrícula, nome e média final. Aprovados tem média igual ou superior a 7;
- Os percentuais de participação das notas podem sofrer mudanças futuramente, bem como a nota de aprovação;
*/

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <stdbool.h>

//Variável para mudar o máximo de alunos para cadastrar
int maxAlunos = 3;

//Struct para a o cadastro do aluno
struct ficha_aluno{
    
    char nome[50];
    char email[50];
    int matricula;
    float A1;
    float A2;
    float A3;
    float media;
    bool ativo;
};
    //Variável da Struct
    struct ficha_aluno aluno[100];


//FUNÇÃO PRINCIPAL
void main (){
    
    while(1){
    //Switch case para escolher a opção do Menu
    int opcaoEscolhida = MenuPrincipal();
    switch (opcaoEscolhida){
    case 1:
        CadastrarAluno();
        break;

    case 2:
        ListarAluno();
        break;
    
    case 3:
        ListarAlunoAprovados();
        break;

    case 4: 
        ListarAlunoReprovados();
        break;

    case 5: 
        ExcluirAluno();
        break;

    case 6:
        exit(0);
        break;

    default:
        printf("\n!!!Escolha umas das quatro opcoes!!!\n");
        break;
    }
    
    }   
}

//Função do Menu Principal
int MenuPrincipal(){
    
    printf("\n\n\n=============================");
    printf("\n     ***MENU PRINCIPAL***");
    printf("\n=============================\n");
    printf("1. Cadastra Aluno\n");
    printf("2. Listar Alunos\n");
    printf("3. Listar Alunos aprovados\n");
    printf("4. Listar Alunos reprovados\n");
    printf("5. Excluir Aluno\n");
    printf("6. Sair\n");

    int opcao;

        do{
        printf("\nEscolha uma das opcoes: ");
        scanf("%d", &opcao);
    }while (opcao < 1 || opcao > 6);

return opcao;
}

//Função para cadastro de aluno
int CadastrarAluno(){
for (int i = 0; i < maxAlunos; i++){

        printf ("------------------------------------------------");

        setbuf(stdin, 0);
        printf("\nNome: ");
        fgets(aluno[i].nome, 50, stdin);

        printf("\nEmail: ");
        scanf("%s", aluno[i].email);

        printf("\nMatricula: ");
        scanf("%d", &aluno[i].matricula);

        printf("\nNota 1: ");
        scanf("%f", &aluno[i].A1);
        
        printf("\nNota 2: ");
        scanf("%f", &aluno[i].A2);
        
        printf("\nNota 3: ");
        scanf("%f", &aluno[i].A3);

        aluno[i].media = ((aluno[i].A1 * 2) + (aluno[i].A2 * 3) + (aluno[i].A3 * 5)) / 10;

        aluno[i].ativo = true;
    }
}

//Função para gravar o aluno 
int ListarAluno(){

for (int i = 0; i < maxAlunos; i++){

            if (aluno[i].ativo){
            printf("\n------------------------------------");
            printf("\nID do aluno: %d", i);
            printf("\nNome: %s", aluno[i].nome);
            printf("\nEmail: %s", aluno[i].email);
            printf("\nMatricula: %d", aluno[i].matricula);
            printf("\nNota A1: %.1f", aluno[i].A1);
            printf("\nNota A2: %.1f", aluno[i].A2);
            printf("\nNota A3: %.1f", aluno[i].A3);
            printf("\nMedia das notas: %.1f", aluno[i].media);
            }
        }
}

//Função para ALUNOS APROVADOS
int ListarAlunoAprovados(){

for (int i = 0; i < maxAlunos; i++){
        if (aluno[i].ativo){
            if (aluno[i].media >= 7){
            printf("\n==============================");
            printf("\n****ALUNOS APROVADOS***");
            printf("\n==============================");
            printf("\nNome: %s", aluno[i].nome);
            printf("\nEmail: %s", aluno[i].email);
            printf("\nMatricula: %d", aluno[i].matricula);
            printf("\nMedia das notas: %.1f", aluno[i].media);
            }
         }
        }
}

//Função para ALUNOS REPROVADOS
int ListarAlunoReprovados(){

for (int i = 0; i < maxAlunos; i++){
        if (aluno[i].ativo){
            if (aluno[i].media < 7){
            printf("\n==============================");
            printf("\n****ALUNOS REPROVADOS***");
            printf("\n==============================");
            printf("\nNome: %s", aluno[i].nome);
            printf("\nEmail: %s", aluno[i].email);
            printf("\nMatricula: %d", aluno[i].matricula);
            printf("\nMedia das notas: %.1f", aluno[i].media);
            }
        }
    }
}

void ExcluirAluno(){
    int escolha;

    printf("\nDigite o ID do aluno que deseja excluir: ");
    scanf("%d", &escolha);
    
    aluno[escolha].ativo = false;
}


