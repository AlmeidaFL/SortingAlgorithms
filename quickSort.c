#include <stdio.h>

int partitionArray(int *array, int begin, int end);
void quickSort(int *array, int begin, int end);
void swap(int *array, int a, int b);

void quickSort(int *array, int begin, int end){
    if(begin < end){
        int pivot_location = partitionArray(array, begin, end);
        quickSort(array, begin, pivot_location);
        quickSort(array, pivot_location+1, end);
    }
}

int partitionArray(int *array, int begin, int end){
    int beginAux = begin, endAux = end + 1;
    int pivot = array[begin];

    while(beginAux < endAux){
        do{
            beginAux++;
        }while((array[beginAux] < pivot) && beginAux < end); //Ate achar um maior que o pivot
        do{
            endAux--;
        }while((array[endAux] > pivot) && endAux > begin); //Ate achar um menor que o pivot
        if(beginAux < endAux) swap(array, beginAux, endAux); 
    }

    swap(array, begin, endAux);
    return endAux;
}

void swap(int *array, int a, int b){
    int aux = array[a];
    array[a] = array[b];
    array[b] = aux;
}

int main(){
    int array[8] = {5,9,1,6,8,2,3,0};

    quickSort(array, 0, 7);

    for(int i = 0; i <= 7; i++){
        printf("%d ", array[i]);
    }


    return 0;
}