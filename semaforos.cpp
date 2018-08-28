#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>  
#include <time.h>
#include <iostream>
using namespace std; 

#define N 10
int buffer[N];
int entrada =0;
int salida =0;
int nItems =0;

sem_t mutex;
sem_t n_sem;
sem_t cero_sem;
 
void* imprimir(void* arg)
{
    while (true) {
      sem_wait(&mutex);
      printf("\nImprimiendo items..\n");
      
      for (int i=0;i<nItems;i++)
        cout << buffer[salida+i] << "  ";
      sleep(3);
      sem_post(&mutex);
    }
    return NULL;
}

void* agregar(void* arg)
{
    while (true) {
      sem_wait(&n_sem);
      sem_wait(&mutex);
      printf("\nAgregando item..\n");
      buffer[entrada] = rand() % 100 + 1;
      entrada = (entrada +1)%N;
      nItems++;
      sleep(3);
      sem_post(&cero_sem);
      sem_post(&mutex);
    }
    return NULL;
}
void* sacar(void* arg)
{   int x;
    while (true) {
      sem_wait(&cero_sem);
      sem_wait(&mutex);
      printf("\nSacando item..\n");
      x = buffer[salida];
      cout << "x= " << x << endl;
      salida = (salida +1)%N;
      nItems--;
      sleep(3);
      sem_post(&n_sem);
      sem_post(&mutex);
    }
    return NULL;
}
 
int main()
{
    srand (time(NULL));
    sem_init(&mutex, 0, 1);
    sem_init(&n_sem, 0, 10);
    sem_init(&cero_sem, 0, 0);
    pthread_t t1,t2,t3;
    pthread_create(&t1,NULL,agregar,NULL);
    pthread_create(&t2,NULL,imprimir,NULL);
    pthread_create(&t3,NULL,sacar,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    for (;;);
    //sem_destroy(&mutex);
    return 0;
}
