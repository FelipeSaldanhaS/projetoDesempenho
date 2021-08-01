//nome: David Belizario Rodrigues – prontuário: gu3011631 – Turma: ADS2ºSEM.

//nome: Felipe Saldanha de Souza – prontuário: gu3011801 – Turma: ADS2ºSEM.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "desempenho.h"
#include <locale.h>
//Variaveis e structs criadas para sustentar tanto o controle das funções de ordenação quanto as variaveis usadas nestas funções.
struct timeval Tempo_antes, Tempo_depois;
double deltaT;
int tam;
int n;
int j;
double vetor[10];
int *temp;
double soma;
double media;

//ordena_bubblesort(int *v, int n): metodo que executa o BubbleSort completo.
void ordena_bubblesort(int *v, int n)
{
    int i, continua, aux, fim = n;
    do
    {
        continua = 0;
        for(i = 0; i<fim - 1; i++)
        {
            if(v[i] > v[i+1])
            {
                aux = v[i];
                v[i] = v[i+1];
                v[1+i] = aux;
                continua = i;
            }
        }
        fim--;
    }
    while(continua != 0);

}
//merge(int *V, int inicio, int meio, int fim): Função do Merge que executa a junção array.
void merge(int *V, int inicio, int meio, int fim)
{
    int *temp, p1, p2, tamanho, i, j, k;

    temp = (int*) malloc(tam * sizeof(int));

    if(temp == NULL)
    {
        printf("ERRO NO MALLOC");
        exit(1);
    }

    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;

    p1 = inicio;
    p2 = meio + 1;

    if(temp != NULL)
    {

        for(i = 0; i<tamanho; i++)
        {

            if(!fim1 && !fim2)
            {

                if(V[p1] < V[p2])

                    temp[i] = V[p1++];
                else

                    temp[i] = V[p2++];

                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }


            else
            {
                if(!fim1)
                    temp[i] = V[p1++];
                else
                    temp[i] = V[p2++];

            }
        }

        for(j = 0, k =  inicio; j<tamanho; j++, k++)
        {
            V[k] =  temp[j];
        }
    }

    free(temp);
}
//void mergeSort(int *V, int inicio, int fim): metodo que executa o MergeSort recursivo, sem ser a parte de junção de array.
void mergeSort(int *V, int inicio, int fim)
{
    int meio;

    if(inicio < fim)
    {
        meio = floor((inicio+fim)/2);

        mergeSort(V,inicio,meio);

        mergeSort(V,meio+1,fim);

        merge(V, inicio, meio, fim);



    }

}
//Ordena_selectionSort(int *vetor, int no): metodo que executa o SelectionSort completo.
int Ordena_selectionSort(int *vetor, int no)
{
    int i, j, menor, troca;
    for(i = 0; i < no -1; i++)
    {
        menor = i;
        for(j = i + 1; j < no; j++)
        {
            if(vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }
        if(i != menor)
        {
            troca = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = troca;
        }
    }

}
//Ordena_insertionSort(int *v, int n): metodo que executa o InsertionSort completo.
int Ordena_insertionSort(int *v, int n)
{
    int i, j, aux;
    for(i = 1; i < n; i++)
    {
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j-1]); j--)
        {
            v[j] = v[j-1];
        }
        v[j] = aux;
    }

}
//radixSort(int *v, int tamanho): metodo que executa o RadixSort completo.
void radixSort(int *v, int tamanho)
{
    int num = tamanho;
    int num_digitos = 0;
    do
    {
        num_digitos++;
        num /= 10;
    }
    while(num != 0);

    int i, j, w, d, posicao;
    int count[10];

    int *aux = (int *)malloc(tamanho * sizeof(int));

    for (w = 0; w < num_digitos; w++)
    {
        for (j = 0; j < 10; j++)
            count[j] = 0;

        for (i = 0; i < tamanho; i++)
        {
            d = (int)(v[i] / (pow(10, w))) % 10;
            count[d]++;
        }

        for (j = 1; j < 10; j++)
            count[j] += count[j - 1];

        for (i = tamanho - 1; i >= 0; i--)
        {
            d = (int)(v[i]/ pow(10,w)) % 10;
            count[d] = count[d] - 1;
            posicao = count[d];
            aux[posicao] = v[i];
        }

        for (int i = 0; i< tamanho; i++)
        {
            v[i] = aux[i];
        }
    }
}
//QuickSort(int *vetor, int esquerda, int direita): metodo que executa o QuickSort completo.
void QuickSort(int *vetor, int esquerda, int direita)
{
    int i, j, meio, troca;
    i = esquerda;
    j= direita;
    meio = vetor[(esquerda+direita)/2];

    while(i <= j)
    {
        while(vetor[i]<meio && i<direita)
        {
            i++;
        }
        while(vetor[j]>meio && j>esquerda)
        {
            j--;
        }
        if(i<=j)
        {
            troca = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = troca;
            i++;
            j--;
        }
    }

    if(j>esquerda)
    {
        QuickSort(vetor, esquerda, j);
    }
    if(i<direita)
    {
        QuickSort(vetor, i, direita);
    }
}
//heapSort(int *vet, int N): metodo que executa o HeapSort parcialmente.
void heapSort(int *vet, int N)
{
    int i, aux;
    for(i=(N-1)/2; i >= 0; i--)
    {
        criaHeap(vet, i, N-1);
    }
    for (i = N-1; i >= 1; i--)
    {
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criaHeap(vet, 0, i - 1);
    }


}
//criaHeap(int *vet, int i, int f): metodo dentro da ideia o heapSort de ordenação
void criaHeap(int *vet, int i, int f)
{
    int aux = vet[i];
    int j = i * 2 + 1;
    while (j <= f)
    {
        if(j < f)
        {
            if(vet[j] < vet[j + 1])
            {
                j = j + 1;
            }
        }
        if(aux < vet[j])
        {
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }
        else
        {
            j = f + 1;
        }
    }
    vet[i] = aux;
}

//Metodos para possibilitar a chamada dos metodos de ordenação.
//-------------------------------------------------------------------------------------------------------------------
//declararTamanho(): serve para declarar o tamanho do vetor dinamicamente alocado.
int declararTamanho()
{
    printf("Quantos elementos deverão ser ordenados? 1000, 5000, 10000, 20000, 50000 ou 100000?\n");
    scanf("%d", &n);
    tam = n;
    return n;
}

//criaVetorRand(int n): cria o vetor dinamicamente alocado com o tamanho herdado de declararTamanho() para executar as funções de ordenação
int criaVetorRand(int n)
{
    temp = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    for (j=0; j < n; j++)
    {
        temp[j] = rand();
    }
    return temp;
}
//inveterVetor(): cria um vetor dinamicamente alocado com valores invertidos para comparação de performance
int inveterVetor()
{
    temp = (int *)malloc(tam * sizeof(int));
    for (j=tam; j >= 0; j--)
    {
        temp[j] = j;
    }
    return temp;

}
//inveterVetor(): cria um vetor dinamicamente alocado com valores ordenado para comparação de performance
int ordenarVetor()
{
    temp = (int *)malloc(tam * sizeof(int));
    for (j=0; j < tam; j++)
    {
        temp[j] = j;
    }
    return temp;
}
//calcularTempoCaso(int *vetor, int sel): Função que vai selecionar o metodo de ordenação a apartir do sel, depois disso imprimir o tempo de execução de cada caso.
void calcularTempoCaso(int *vetor, int sel)
{
    gettimeofday (&Tempo_antes, NULL);

    switch(sel)
    {
    case 1:
        ordena_bubblesort(vetor, n);
        break;
    case 2:
        Ordena_insertionSort(vetor, n);
        break;
    case 3:
        Ordena_selectionSort(vetor, n);
        break;
    case 4:
        radixSort(vetor, n);
        break;
    case 5:
        mergeSort(vetor,0, n - 1);
        break;
    case 6:
        QuickSort(vetor, 0, n-1);
        break;
    case 7:
        heapSort(vetor, n);
        break;

    }


    gettimeofday (&Tempo_depois, NULL);

    deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0) -
             (Tempo_antes.tv_sec + Tempo_antes.tv_usec/1000000.0);

    printf("Tempo: %f\n",deltaT);

}

//calcularTempoCasoMedia(int *vetor, int sel): Função que vai selecionar o metodo de ordenação a apartir do sel, depois disso imprimir o tempo de execução do caso médio.
void calcularTempoCasoMedia(int *vetorM, int sel)
{
    for (j=0; j <= 10; j++)
    {

        gettimeofday (&Tempo_antes, NULL);

        switch(sel)
        {
        case 1:
            ordena_bubblesort(vetorM, n);
            break;
        case 2:
            Ordena_insertionSort(vetorM, n);
            break;
        case 3:
            Ordena_selectionSort(vetorM, n);
            break;
        case 4:
            radixSort(vetorM, n);
            break;
        case 5:
            mergeSort(vetorM,0, n - 1);
            break;
        case 6:
            QuickSort(vetorM, 0, n-1);
            break;
        case 7:
            heapSort(vetorM, n);
            break;

        }

        gettimeofday (&Tempo_depois, NULL);

        deltaT = (Tempo_depois.tv_sec + Tempo_depois.tv_usec/1000000.0) -
                 (Tempo_antes.tv_sec + Tempo_antes.tv_usec/1000000.0);

        vetor[j] = deltaT;

    }

    soma = 0;

    for (j=0; j <= 10; j++)
    {
        soma = soma + vetor[j];
    }
    media = soma/10;

    printf("Tempo: %f\n",media);

}




