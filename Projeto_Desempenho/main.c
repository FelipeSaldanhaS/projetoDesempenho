//nome: David Belizario Rodrigues � prontu�rio: gu3011631 � Turma: ADS2�SEM.

//nome: Felipe Saldanha de Souza � prontu�rio: gu3011801 � Turma: ADS2�SEM.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "desempenho.h"
#include <locale.h>
//Bibliotecas padr�es, al�m da time, locale e do desempenho.h, necess�rios para executar as fun��es futuras e facilitar o entendimento.

int main()
{
    setlocale(LC_ALL, "Portuguese");
    //Variaveis para controle do menu, controle dos fors e uso do vetor dinamicamente alocado.
    int menu;
    int j;
    int *v;
    int num;
    int I;


    menu = 1;

    while(menu)
    {
        //while criado para repetir as fun��es do menu.
        I=0;
        //O I sempre voltar� a zero para n�o criar um loop infinito.
        printf("\n//////////////////////////////////\n");
        printf("\nMENU - ALGORITMOS ");
        printf("ESCOLHA UM ALGORTIMO:\n");
        printf(" 1- BubbleSort\n");
        printf(" 2- InsertionSort\n");
        printf(" 3- SelectionSort\n");
        printf(" 4- RadixSort\n");
        printf(" 5- MergeSort \n");
        printf(" 6- QuickSort\n");
        printf(" 7- HeapSort\n");
        printf(" 8-Sair da aplica��o\n");

        //Scanf para escolher uma op��o do menu.
        printf("Escolha: \n");
        scanf("%d", &I);

        //Switch usando do I para poder escolher um dos casos do menu.
        switch(I)
        {
        //Caso 2: Executando o BubbleSort com diversos metodos e exibindo valores de performance.
        case 1:
//M�dia
            v = criaVetorRand(declararTamanho());

            printf("A m�dia de tempo de execu��o do algoritmo desordenado Bubblesort foi de: \n");

            calcularTempoCasoMedia(v,I);
//Ordenar o ordenado

            printf("O tempo de execu��o com o algoritmo bubblesort j� ordenado foi de: \n");

            v = ordenarVetor();

            calcularTempoCaso(v,I);


//Inveter
            printf("O tempo de execu��o com o algoritmo bubblesort invertido foi de: \n");
            v = inveterVetor();

            calcularTempoCaso(v,I);

            system("pause");

            break;
        //Caso 2: Executando o InsertionSort com diversos metodos e exibindo valores de performance.
        case 2:
//M�dia
            v = criaVetorRand(declararTamanho());

            printf("A m�dia de tempo de execu��o do algoritmo desordenado InsertionSort foi de: \n");

            calcularTempoCasoMedia(v,I);
//Ordenar o ordenado

            printf("O tempo de execu��o com o algoritmo InsertionSort j� ordenado foi de: \n");

            v = ordenarVetor();

            calcularTempoCaso(v,I);


//Inveter
            printf("O tempo de execu��o com o algoritmo InsertionSort invertido foi de: \n");
            v = inveterVetor();

            calcularTempoCaso(v,I);

            system("pause");

            break;
        //Caso 3: Executando o SelectionSort com diversos metodos e exibindo valores de performance.
        case 3:
//M�dia
            v = criaVetorRand(declararTamanho());

            printf("A m�dia de tempo de execu��o do algoritmo desordenado SelectionSort foi de: \n");

            calcularTempoCasoMedia(v,I);
//Ordenar o ordenado

            printf("O tempo de execu��o com o algoritmo SelectionSort j� ordenado foi de: \n");

            v = ordenarVetor();

            calcularTempoCaso(v,I);


//Inveter
            printf("O tempo de execu��o com o algoritmo SelectionSort invertido foi de: \n");
            v = inveterVetor();

            calcularTempoCaso(v,I);

            system("pause");

            break;
        //Caso 4: Executando o RadixSort com diversos metodos e exibindo valores de performance.
        case 4:
//M�dia
            v = criaVetorRand(declararTamanho());

            printf("A m�dia de tempo de execu��o do algoritmo desordenado RadixSort foi de: \n");

            calcularTempoCasoMedia(v,I);
            //------------------
            v = ordenarVetor();
            printf("O tempo de execu��o com o algoritmo RadixSort j� ordenado foi de: \n");

            calcularTempoCaso(v,I);

            //------------------
            v = inveterVetor();

            printf("O tempo de execu��o com o algoritmo RadixSort invertido foi de:\n");

            calcularTempoCaso(v,I);

            system("pause");


            break;
        //Caso 5: Executando o MergeSort com diversos metodos e exibindo valores de performance.
        case 5:
//M�dia
            v = criaVetorRand(declararTamanho());

            printf("A m�dia de tempo de execu��o do algoritmo desordenado MergeSort foi de: \n");

            calcularTempoCasoMedia(v,I);
            //------------------
            v = ordenarVetor();
            printf("O tempo de execu��o com o algoritmo MergeSort j� ordenado foi de: \n");

            calcularTempoCaso(v,I);

            //------------------
            v = inveterVetor();

            printf("O tempo de execu��o com o algoritmo MergeSort invertido foi de:\n");

            calcularTempoCaso(v,I);

            system("pause");


            break;
        //Caso 6: Executando o QuickSort com diversos metodos e exibindo valores de performance.
        case 6:
//M�dia
            v = criaVetorRand(declararTamanho());

            printf("A m�dia de tempo de execu��o do algoritmo desordenado QuickSort foi de: \n");

            calcularTempoCasoMedia(v,I);
            //------------------
            v = ordenarVetor();
            printf("O tempo de execu��o com o algoritmo QuickSort j� ordenado foi de: \n");

            calcularTempoCaso(v,I);

            //------------------
            v = inveterVetor();

            printf("O tempo de execu��o com o algoritmo QuickSort invertido foi de:\n");

            calcularTempoCaso(v,I);

            system("pause");


            break;
        //Caso 7: Executando o HeapSort com diversos metodos e exibindo valores de performance.
        case 7:
//M�dia
            v = criaVetorRand(declararTamanho());

            printf("A m�dia de tempo de execu��o do algoritmo desordenado HeapSort foi de: \n");

            calcularTempoCasoMedia(v,I);
            //------------------
            v = ordenarVetor();
            printf("O tempo de execu��o com o algoritmo HeapSort j� ordenado foi de: \n");

            calcularTempoCaso(v,I);

            //------------------
            v = inveterVetor();

            printf("O tempo de execu��o com o algoritmo HeapSort invertido foi de:\n");

            calcularTempoCaso(v,I);

            system("pause");


            break;
        //Caso 8: Saindo do menu e consequentemente da aplica��o.
        case 8:
            printf("Saindo da aplica��o!\n");
            menu = 0;
            break;
        //Caso default: N�o executando nada e encaminhando para reiniciar o loop.
        default:
            printf("\n//////////////////////////////////\n");
            printf("Valor inv�lido, retornando ao menu!\n");

        }


    }
    //Free para liberar o vetor dinamicamente alocado.
    free(v);
    return 0;
}
