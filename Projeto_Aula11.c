#include <iostream>
#include <string>
#include <strings.h>
using namespace std;
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
- listar os alunos cadstrados com matrícula, nome, notas A1, A2 e A3, altém da média final
- A média é conposta de A1 valendo 20% da nota final, A2 30% da nota final e A3 valendo 50% da nota final;
- Listar os alunos aprovados com matrícula, nome e média final. Aprovados tem média igual ou superior a 7;
- Listar os alunos reprovados com matrícula, nome e média final. Aprovados tem média igual ou superior a 7;
- Os percentuais de participação das notas podem sofrer mudanças futuramente, bem como a nota de aprovação;
*/

typedef struct  {
    //char nome[40];    
    char nome[50];
    char email[50];
    int matricula = -1;
    float A1;
    float A2;
    float A3;
} Aluno;

void limpaTela() {
    printf("\e[1;1H\e[2J");
}

int menuPrincipal() {
    //limpaTela();
    printf("Menu Principal\n");
    printf("==============\n");
    printf("1. cadastrar aluno\n");
    printf("2. listar alunos\n");
    printf("3. exlcuir aluno\n");
    printf("0. sair\n\n");
    
    int opt = 0;
    do {
        printf("informe opcao desejada: ");
        scanf("%i", &opt);
    } while (opt < 0 || opt > 3);
    
    return opt;
}

void gravaAluno(int posicao, Aluno alunos[100]) {
        printf("(%d) Informe o nome: ", posicao);
        // get up to buffer size - 1 characters (to account for NULL terminator)
        //scanf("%s", alunos[posicao].nome);
        char temp[50];
        scanf("%s", temp);
        
        strcpy(alunos[posicao].nome,temp);

        printf("Informe o email: ");
        // get up to buffer size - 1 characters (to account for NULL terminator)
        scanf("%s", alunos[posicao].email);
        printf("Informe o número da matrícula: ");
        scanf("%i", &alunos[posicao].matricula);
        printf("Informe a A1: ");
        scanf("%f", &alunos[posicao].A1);
        printf("Informe a A2: ");
        scanf("%f", &alunos[posicao].A2);
        printf("Informe a A3: ");
        scanf("%f", &alunos[posicao].A3);
        printf("---------\n");
    
}

int listarAlunos(Aluno cadAlunos[]) {
    for( int x = 0; x < 100; x++) {
            printf("%d %i\n", x, cadAlunos[x].matricula);
            if (cadAlunos[x].matricula != -1) {
                printf("Nome: %s email: %s Matrícula: %d\n", cadAlunos[x].nome, 
                cadAlunos[x].email, cadAlunos[x].matricula);
            }
        }
        return 0;
}
void zeraCadastro(Aluno alunos[]) {
    for (int i = 0 ; i < 100; i++){
        alunos[i].matricula = -1;
    }
 }

int primeiroDisponivel(int matr[10]) {
    int ret = -1;
    for (int i = 0 ; i < 10; i++){
        if (matr[i] == -1) { 
            ret = i;
            break;
        }
    }
    return ret;
}



int main(int argc, char const *argv[]) {
/*
    char nome[10][50]; 
    char email[10][50];
    int matricula[10];
    float A1[10], A2[10], A3[10];
        //zeraCadastro(matricula);
*/
// substitui por
    Aluno cadAlunos[100];

    zeraCadastro(cadAlunos);

    //printf("\e[1;1H\e[2J");
    limpaTela();
    while (true) {
        int menu  = menuPrincipal();
        switch (menu) {
            case 1: {
                //printf("informe a posicao que quer gravar: 1 ~ 10 :");
                int i = 0; //primeiroDisponivel(matricula);
                //scanf("%i", &i);
                //gravaAluno(i, nome, email, matricula, A1, A2, A3);
                gravaAluno(i, cadAlunos);
                
                break;
            }
            case 2: {
            listarAlunos(cadAlunos);
            break;
            }
            
        }
        
        
    }
    //printf("Nome: %s\nemail: %s\nMatrícula: %d\n", nome[1], email[1], matricula[1]);
    //printf("Nome: %s\nemail: %s\nMatrícula: %d\n", nome[2], email[2], matricula[2]);
    

    //limpar console
    //printf("\e[1;1H\e[2J");

    char name[20];

    // get up to buffer size - 1 characters (to account for NULL terminator)
    scanf("%19[^\n]", name);

}































/*
typedef struct  {
    //char nome[40];    
    char *nome;
    int matricula;
    int a1;
    int a2;
    int a3
} Aluno;
//strcpy(alu1.nome,"Jean Paul");
*/