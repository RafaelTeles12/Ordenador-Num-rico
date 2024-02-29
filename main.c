#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int num[], int tam) { 
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++) 
  {
    min = i;
    for (j = (i+1); j < tam; j++) {
      if(num[j] < num[min]) 
      min = j;
    }
    
    if (i != min) {
      aux = num[i];
      num[i] = num[min];
      num[min] = aux;
    }
  }
}

void insertionSort(int arr[], int size){
  int i, j, key;
  for (i = 1; i < size; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void radixSort(int vetor[], int tamanho) {
  
  int i;
  int *b;
  int maior = vetor[0];
  int exp = 1;

  b = (int *)calloc(tamanho, sizeof(int));

  for (i = 0; i < tamanho; i++) {
    if (vetor[i] > maior)
    maior = vetor[i];
  }

  while (maior/exp > 0) {
    int bucket[10] = { 0 };
    for (i = 0; i < tamanho; i++)
    	bucket[(vetor[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
    	bucket[i] += bucket[i - 1];
    for (i = tamanho - 1; i >= 0; i--)
    	b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    for (i = 0; i < tamanho; i++)
    	vetor[i] = b[i];
    exp *= 10;
  }

  free(b);
}

int*lista;
int tam;
clock_t t;

int exec(void){
  
  int opcao=0;

  do{
    
    printf("\n\n- Modos de ordenação -\n\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Radix Sort\n");
    printf("0. Sair.\n\n");
    printf("Digite a opção desejada: ");
    
    scanf("%d",&opcao);
  
    switch(opcao){
      case 1:
        t = clock();
        selectionSort(lista,tam);
        t = clock() - t;
        printf("\n");
        for(int i=0;i<tam;i++){
          printf("%d ",lista[i]);
        }
        printf("\n\nTempo de execução: %.4lf ms", ((double)t)/((CLOCKS_PER_SEC)/1000));
      break;
  
      case 2:
        t = clock();
        insertionSort(lista,tam);
        t = clock() - t;
        printf("\n");
        for(int i=0;i<tam;i++){
          printf("%d ",lista[i]);
        }
        printf("\n\nTempo de execução: %.4lf ms", ((double)t)/((CLOCKS_PER_SEC)/1000));
      break;

      case 3:
        t = clock();
        radixSort(lista,tam);
        t = clock() - t;
        printf("\n");
        for(int i=0;i<tam;i++){
          printf("%d ",lista[i]);
        }
        printf("\n\nTempo de execução: %.4lf ms", ((double)t)/((CLOCKS_PER_SEC)/1000));
      break;
  
      case 0:
        printf("Sair do Menu!\n\n");
        free(lista);
      break;
  
      default:
      printf("Opção inválida, tente novamente.");
    }
    
  } while(opcao!=0);

  return(opcao);
}

void listaManual(void){
  
  system("clear");
  
  printf("-- Lista Manual --\n\n");
  printf("Quantos números terá a lista? ");
  scanf("%d",&tam);

  lista = (int *) malloc(tam*sizeof(int));
  
  printf("\nDigite os números da lista:\n\n");

  for(int i=0;i<tam;i++){
    scanf("%d",&lista[i]);
  }

  printf("\nLista gravada com sucesso!");
  
  exec();
}

void listaAleatoria(void){

  system("clear");
  
  int max;
  
  printf("-- Lista Aleatória --\n\n");
  printf("Quantos números terá a lista? ");
  scanf("%d",&tam);

  printf("\nQual será o tamanho máximo dos números? ");
  scanf("%d",&max);

  while(max<tam-1){
    printf("\nPara uma lista de %d números, o tamanho máximo dos números precisa ser maior que %d.\n",tam,tam-2);
    printf("\nQual será o tamanho máximo dos números? ");
    scanf("%d",&max);
  }
  
  lista = (int *) malloc(tam*sizeof(int));
  
  srand(time(NULL));
  
  for (int i=0; i<tam; i++) {
    lista[i] = rand()%(max+1);
    int rep = 0;
    for (int j=0; j<i && rep == 0; j++) {
      if (lista[i] == lista[j])
      rep = 1;
    }

    if (rep == 1){i--;}
  }

  printf("\n");
  
  for(int i=0;i<tam;i++){
    printf("%d ",lista[i]);
  }
  printf("\n\nLista gravada com sucesso!");

  exec();
}

int menuPrincipal(void){

  int opcao=0;

  do{
    printf("--- Ordenador Numérico ---\n\n");
    printf("1. Gerar lista manual\n");
    printf("2. Gerar lista aleatória\n");
    printf("0. Sair.\n\n");
    printf("Digite a opção desejada: ");
    
    scanf("%d",&opcao);
  
    switch(opcao){
      case 1:
        listaManual();
      break;
  
      case 2:
        listaAleatoria();
      break;
  
      case 0:
        printf("Sair do Menu!\n");
      break;
  
      default:
      printf("Opção inválida, tente novamente.\n\n");
    }
    
  } while(opcao!=0);
    
  return (opcao);
}

int main(void){
  menuPrincipal();
  return 0;
}