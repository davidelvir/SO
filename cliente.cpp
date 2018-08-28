#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <iostream>
#include <pthread.h>

using namespace std;

#define SHM_SIZE 1024

struct Segmento
{
    bool serverFlag;
    bool clientFlag;
    char mensajeC[SHM_SIZE];
    char mensajeS[SHM_SIZE];
};

void *readSegmento(void *);
void *writeSegmento(void *);

Segmento *data;

int main(int argc, char *argv[])
{
    key_t key = 5644;
    int shmid;
    int mode;

    /* Crear el segmento */
    if ((shmid = shmget(key, sizeof(struct Segmento), 0644)) == -1)
    {
        perror("shmget");
        exit(1);
    }

    data = (Segmento *)shmat(shmid, NULL, 0);
    if (data == (Segmento *)(-1))
    {
        perror("shmat");
        exit(1);
    }

    pthread_t threads[2];

    int iret1, iret2;

    iret1 = pthread_create(&threads[0], NULL, readSegmento, NULL);
    iret2 = pthread_create(&threads[0], NULL, writeSegmento, NULL);

    for(int i=0; i<2; i++){
        pthread_join(threads[i],NULL);
    }
    //cout << data << endl;

    /*
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }
    */
    return 0;
}
void *readSegmento(void *)
{
    while (true)
    {
        data->clientFlag = true;
        while (data->clientFlag)
            ;
        cout << data->mensajeC << endl;
    }
}
void *writeSegmento(void *)
{
    char cadena[SHM_SIZE];

    while (true)
    {
        cout << ":>";
        cin.getline(cadena, SHM_SIZE);
        strcpy(data->mensajeS, cadena);
        data->serverFlag = false;
    }
}
