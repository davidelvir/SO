#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

#define N 10;
int x;
int nL;

sem_t mutex;
sem_t mutexL;

void *leer(void *arg)
{
    while (true)
    {

        cout<<"leer esperando"<<endl;
        sem_wait(&mutexL);
        if (nL == 0)
        {
            sem_wait(&mutex);
        }
        nL++;
        sem_post(&mutexL);
        printf("EL valor de x es: %d\n", x);
        sem_wait(&mutexL);
        nL--;
        if (nL == 0)
        {
            sem_post(&mutex);
        }
        sem_post(&mutexL);
        sleep(3);
    }
    return NULL;
}

void *escribir(void *arg)
{
    while (true)
    {
        sem_wait(&mutex);
        x++;
        sem_post(&mutex);
        sleep(3);
    }
    return NULL;
}

int main()
{
   
    sem_init(&mutex, 0, 1);
    sem_init(&mutexL, 0, 1);
    nL = 0;
    x = 1;
    pthread_t t1,t2;

    pthread_create(&t1,NULL,leer,NULL);
    pthread_create(&t2,NULL,escribir,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    for (;;)
        ;
    //sem_destroy(&mutex);
    return 0;
}
