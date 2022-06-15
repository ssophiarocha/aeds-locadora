#include <stdio.h>
#include <stdlib.h>

struct sVeiculos
{
    int numero;
    char placa[10];
    char marca[20];
    char modelo[20];
    char ano [5];
    char categoria[10];
    char assentos[5];
};
typedef struct sVeiculos tVeiculos;
tVeiculos vetVeiculos[100];

struct sClientes
{
    int codigo;
    char nome[30];
    char cnh[20];
    char telefone[20];
    char endereco[40];
};
typedef struct sClientes tClientes;
tClientes vetClientes[100];

int main()
{
    int opcao;
    carregaClientes();
    carregaVeiculos();

    printf("\n---------------------------------------------\n");
    printf("\n------------------LOCAMAIS-------------------\n");
    printf("\n---------------------------------------------\n");

    printf("\n(1) Cadastrar veiculo\n(2) Cadastrar cliente\n(3) Cadastrar locacao\n(4) Validar locacao\n(5) Pesquisar clientes\n(6) Listar clientes\n(7) Pesquisar veiculos\n(8) Lista veiculos\n(9) Imprimir veiculos\n(10) Imprimir clientes\n Caso queira SAIR, digite 0\n");

    printf("Digite um numero para executar a funcao: ");
    scanf("%d", &opcao);

    while (opcao != 0)
    {
        switch (opcao)
        {
        case 1:
            cadastraveiculo();
            break;
        case 2:
            cadastracliente();
            break;
        case 3:
            cadastraloc();
            break;
        case 4:
            validaloc();
            break;
        case 5:
            pesquisacliente();
            break;
        case 6:
            listacliente();
            break;
        case 7:
            pesquisaveiculo();
            break;
        case 8:
            listaveiculo();
            break;
        case 9:
            printVeiculos();
            break;
        case 10:
            printClientes();
            break;
        }
        printf("\n \n  O que mais voce deseja? \n \n");
        printf("\n(1) Cadastrar veiculo\n(2) Cadastrar cliente\n(3) Cadastrar locacao\n(4) Validar locacao\n(5) Pesquisar clientes\n(6) Listar clientes\n(7) Pesquisar veiculos\n(8) Lista veiculos\n(9) Imprimir veiculos\n(10) Imprimir clientes\nCaso queira SAIR, digite 0\n");

    printf("\n Digite um numero para executar a funcao: ");
    scanf("%d", &opcao);
    }


}
int carregaClientes()
{
    int j=0,k=0;
    char nomeCampoc[256],valorCampoc[256];
    FILE *arqClientes;
    arqClientes = fopen("clientes.txt", "r");
    if (arqClientes != NULL)
    {
        k = fscanf(arqClientes, "%s %[^\n]", &nomeCampoc, &valorCampoc);
        j = 0;
        while (k != EOF)
        {
            if (strcmp(nomeCampoc,"cliente")==0 && strcmp(valorCampoc, "inicio")==0)
            {
                j = j +1;
                vetClientes[j].codigo = j;
                strcpy(vetClientes[j].nome,"");
                strcpy(vetClientes[j].cnh,"");
                strcpy(vetClientes[j].telefone,"");
                strcpy(vetClientes[j].endereco,"");
            }
            if (strcmp(nomeCampoc,"nome")==0)
                strcpy(vetClientes[j].nome,valorCampoc);
            if (strcmp(nomeCampoc,"cnh")==0)
                strcpy(vetClientes[j].cnh,valorCampoc);
            if (strcmp(nomeCampoc,"telefone")==0)
                strcpy(vetClientes[j].telefone,valorCampoc);
            if (strcmp(nomeCampoc,"endereco")==0)
                strcpy(vetClientes[j].endereco,valorCampoc);

            k = fscanf(arqClientes,"%s %[^\n}]",&nomeCampoc,&valorCampoc);
        }
        j = j + 1;
        vetClientes[j].codigo = 999;
        fclose(arqClientes);
    }
    else
    {
        printf("arquivo clientes.txt nao encontrado");
        k = -1;
    }
    return k;
}

int carregaVeiculos()
{
    int i=0,r=0;
    char nomeCampo[256],valorCampo[256];
    FILE *arqVeiculos;
    arqVeiculos = fopen("veiculos.txt", "r");
    if (arqVeiculos != NULL)
    {
        r = fscanf(arqVeiculos,"%s %[^\n]", &nomeCampo, &valorCampo);
        i = 0;
        while (r != EOF)
        {
            if (strcmp(nomeCampo,"veiculo")== 0 && strcmp(valorCampo, "inicio")== 0)
            {
                i = i +1;
                vetVeiculos[i].numero = i;
                strcpy(vetVeiculos[i].placa,"");
                strcpy(vetVeiculos[i].marca,"");
                strcpy(vetVeiculos[i].modelo,"");
                strcpy(vetVeiculos[i].ano,"");
                strcpy(vetVeiculos[i].categoria,"");
                strcpy(vetVeiculos[i].assentos,"");
            }
            if (strcmp(nomeCampo,"placa")==0)
                strcpy(vetVeiculos[i].placa,valorCampo);
            if (strcmp(nomeCampo,"marca")==0)
                strcpy(vetVeiculos[i].marca,valorCampo);
            if (strcmp(nomeCampo,"modelo")==0)
                strcpy(vetVeiculos[i].modelo,valorCampo);
            if (strcmp(nomeCampo,"ano")==0)
                strcpy(vetVeiculos[i].ano,valorCampo);
            if (strcmp(nomeCampo,"categoria")==0)
                strcpy(vetVeiculos[i].categoria,valorCampo);

            r = fscanf(arqVeiculos,"%s %[^\n}]",&nomeCampo,&valorCampo);
        }
        i = i + 1;
        vetVeiculos[i].numero = 999;
        fclose(arqVeiculos);
    }
    else
    {
        printf("arquivo veiculos.txt nao encontrado");
        r = -1;
    }
    return r;
}

void printVeiculos()
{
    for (int i = 1; i<100 && vetVeiculos[i].numero != 999; i++)
    {
        printf("\n%i %s %s %s %s %s", vetVeiculos[i].numero,
               vetVeiculos[i].placa,
               vetVeiculos[i].marca,
               vetVeiculos[i].modelo,
               vetVeiculos[i].ano,
               vetVeiculos[i].categoria );
    }
}
void printClientes()
{

    for (int j = 1; j<100 && vetClientes[j].codigo != 999; j++)
    {
        printf("\n%i %s %s %s %s", vetClientes[j].codigo,
               vetClientes[j].nome,
               vetClientes[j].cnh,
               vetClientes[j].telefone,
               vetClientes[j].endereco);
    }
}

void cadastraveiculo()
{

    printf ("1");

}

void cadastracliente()
{

    printf ("2");

}

void cadastraloc()
{

    printf ("3");

}

void validaloc()
{

    printf ("4");

}

void pesquisacliente()
{

    printf ("5");

}

void listacliente()
{

    printf ("6");

}

void pesquisaveiculo()
{

    printf ("7");

}

void listaveiculo()
{

    printf ("8");

}
