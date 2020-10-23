#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq->size== 0){
    return NULL;
  }
  if(pq->heapArray[0].data == 0){
    return NULL;
  }
  return pq->heapArray[0].data;
}


void heap_push(Heap* pq, void* data, int priority){
  if(pq->size+1 > pq->capac){
    pq->capac = (pq->capac) * 2 + 1;
    pq->heapArray = realloc (pq->heapArray, (pq->capac) * sizeof(heapElem));
  }

  int actual = pq->size;
  while(actual > 0 && pq->heapArray[(actual-1)/2].priority < priority){
    pq->heapArray[actual] = pq->heapArray[(actual-1)/2];
    actual = (actual-1)/2;
  }
  pq->heapArray[actual].priority = priority;
  pq->heapArray[actual].data = data;
  pq->size++;
}

void heap_pop(Heap* pq){
}

Heap* createHeap(){
  Heap * heap = (Heap*) malloc (sizeof(Heap)); //Se le asigna memoria al monticulo
  heap->size = 0; //Se inicializa en 0 ya que aun no tiene anda el arreglo
  heap->capac = 3; //Se inicializa la capacidad en 3
  heap->heapArray = (heapElem*) calloc (10, sizeof(heapElem)); //Se le asigna memoria al arreglo del monticulo
  return heap; //Se retorna el monticulo creado
}
