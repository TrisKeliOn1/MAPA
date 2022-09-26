#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define max 200

struct vaccine{
    int code;
    char name[30];
    char id[30]; 
    char date[15];
    char factory[30];
    char lote[10];
};

struct vaccine project[max];

int i = 0;

void cadastrar();
void modificar();
void listar();
void busca_codigo();
void busca_status();

int main(){
    setlocale(LC_ALL, "portuguese");
    struct vaccine project[max];

    int y;

    system("cls");
    do{
        system("cls");
        printf(" _______________________________________________________\n");
        printf("|                                                       |\n");
        printf("|                           Menu                        |\n");
        printf("|                 1 - Cadastrar vacina                  |\n");
        printf("|                 2 - Lista Aplicações                  |\n");
        printf("|                 3 - Buscar por cpf                    |\n");
        printf("|                 4 - Sair                              |\n");
        printf("|                                                       |\n");
        printf("|_______________________________________________________|\n");
        printf("\n");
        printf("Selecione a opção desejada: ");
        fflush(stdin);
        scanf("%d", &y);

        switch (y){
            case 1:
                cadastrar();
                break;
            case 2:
                lista();
                break;
            case 3:
            	fflush(stdin);
                busca_codigo();
                break;
            case 4:
                printf("\nFinalizando...\n");
                printf("\n");
                system("pause");
                break;
            default:
                printf("\nOpção inválida\n");
                system("pause");
        }
    }while(y != 4);
    return 0;
}

void cadastrar(){
    system("cls");
    printf(" _______________________________________________________\n");
    printf("|                                                       |\n");
    printf("|                                                       |\n");
    printf("|                  CADASTRO DE VACINA                   |\n");
    printf("|                                                       |\n");
    printf("|_______________________________________________________|\n");
    char resp = 's';

    while(resp == 's' && i < max){
        i++;

        printf("\nPaciente: %d \n", i);
        project[i].code = i;

        printf("Digite o nome do paciente: ");
        fflush(stdin);
        gets(project[i].name);

        printf("Digite o CPF do paciente: ");
        fflush(stdin);
        gets(project[i].id);

        printf("Digite a data: ");
        fflush(stdin);
        scanf("%s", &project[i].date);
        
        printf("Digite a vacina aplicada: ");
        fflush(stdin);
        gets(project[i].factory);

        printf("Digite o lote da vacina: ");
        fflush(stdin);
        gets(project[i].lote);


        printf("________________________________________________________\n");

        if (i < max){
            printf("\nDeseja cadastrar outro projeto? (s/n): ");
            fflush(stdin);
            scanf("%c", &resp);
        }else{
            resp = 'n';
        }
    }
    if (i >= max){
        printf("\nLimite de cadastro atingido!\n");
        printf("\n");
        system("pause");
    }
}


void lista(){
    system("cls");
    printf(" _______________________________________________________\n");
    printf("|                                                       |\n");
    printf("|                                                       |\n");
    printf("|                   LISTA DE APLICAÇÃO                  |\n");
    printf("|                                                       |\n");
    printf("|_______________________________________________________|\n");
    int j;

    for (j = 1; j != max; j++){
        if (project[j].code != 0){
            printf("\n");
            printf("código: %d\n", project[j].code);
            printf("Nome do paciente: %s\n", project[j].name);
            printf("CPF do paciente: %s\n", project[j].id);
            printf("Nome da vacina: %s\n", project[j].factory);
            printf("Lote: %s\n", project[j].lote);
            printf("_____________________________\n");
            }
        }
    system("pause");
}

void busca_codigo(){
    system("cls");
    printf(" _______________________________________________________\n");
    printf("|                                                       |\n");
    printf("|                                                       |\n");
    printf("|                    BUSCA POR CPF                      |\n");
    printf("|                                                       |\n");
    printf("|_______________________________________________________|\n");

    int  again;
    char cont[20];
    int w = 0;
    again = 0;
    printf("\nInforme o CPF do paciente: ");
    gets(cont);
    fflush(stdin);
    printf("\n");

    while((again == 0) && (w <= i)){
        if(strcmp(cont, project[w].id)==0){
           
            printf("Descrição: %d\n", project[w].code);
        	printf("Nome do paciente: %s\n", project[w].name);
            printf("CPF do paciente: %s\n", project[w].id);
            printf("Nome da vacina: %s\n", project[w].factory);
            printf("Lote: %s\n", project[w].lote);
            printf("_____________________________\n");
          
            printf("\n");
            again = 1;
            system("pause");
        }
        w++;
    }
        if(again == 0){
            printf("\nRegistro nao encontrado.\n");
            printf("\n");
            system("pause");
        }
        system("PAUSE");
}
