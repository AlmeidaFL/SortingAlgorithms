#include <stdio.h>

void mergeSort(int* array, int begin, int end);


void merge(int *array, int begin, int half, int end){
    int aux[end];

    for(int i = begin; i <= end; i++) aux[i] = array[i]; //assistant array

    int partitionA = begin, partitionB = half+1;

    int i = begin;
    do{
        if(aux[partitionA] <= aux[partitionB]){
            array[i] = aux[partitionA];
            partitionA++;
        }else{
            array[i] = aux[partitionB];
            partitionB++;
        }
        i++;
    }while((partitionA <= half) && (partitionB <= end));

    if(partitionA > half){
        for(int c = partitionB; c <= end; c++){
            array[i] = aux[c];
            i++;
        }
    }else{
        for(int c = partitionA; c <= half; c++){
            array[i] = aux[c];
            i++;
        }
    }

}

void mergeSort(int* array, int begin, int end){
    if(begin < end){
        int half = (begin+end)/2;
        mergeSort(array, begin, half);
        mergeSort(array, half+1, end);
        merge(array, begin, half, end);
    }
}


int main(){

    int array[11] = {5, 2, 4, 7, 1, 3, 6, 8, -2, -10, 4};
    mergeSort(array, 0, 10);

    for(int i = 0; i < 11; i++){
        printf("%d ", array[i]);
    }

    return 0;
}