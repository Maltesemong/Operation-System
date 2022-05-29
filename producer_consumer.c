#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>

sem_t mutex;
sem_t full;
sem_t empty;

typedef int buff;
buff buffer[2];
int i;

void put(buff value)
{
        if( i < 2 )
        {
                buffer[i++] = value;
        }
        else
        {
                printf("Overflow\n");
        }
}

buff get()
{
        if (i > 0)
        {
                return buffer[--i];
        }
        else
        {
                printf("Underflow\n");
        }
        return 0;
}

void *producer(void *thread_n)
{
        int t_num = *(int *)thread_n;
        buff value;
        for( int i = 0; i < 2; i++)
        {
                sleep(rand() % 10);
                value = rand() % 100;
								sem_wait(&full);
                sem_wait(&mutex);
                put(value);
                sem_post(&mutex);
                sem_post(&empty);
                printf("Produced %d added %d to buffer\n", t_num, value);
        }
        pthread_exit(0);
}

void *consumer(void *thread_n)
{
        int t_num = *(int *)thread_n;
        buff value;
        for (int i = 0; i < 2; i++)
        {
                sem_wait(&empty);
                sem_wait(&mutex);
                value = get(value);
                sem_post(&mutex);
                sem_post(&full);
                printf("Consumer %d dequeue %d from buffer\n", t_num, value);
        }
        pthread_exit(0);
}

int main(int argc, int **argv)
{
        i = 0;
        sem_init(&mutex, 0, 1);
        sem_init(&full, 0, 2);
        sem_init(&empty, 0, 0);

        pthread_t thread[4];
        int thread_numb[4];
        int j;
        for (j = 0; j < 4;)
        {
                thread_numb[j] = j;
                pthread_create(thread + j, NULL, producer, thread_numb + j);
                j++;
                thread_numb[j] = j;

                pthread_create(&thread[i], NULL, consumer, &thread_numb[j]);
                j++;
        }
        for (j = 0; j < 4; j++)
        {
								pthread_join(thread[j], NULL);
        }

        sem_destroy(&mutex);
        sem_destroy(&full);
        sem_destroy(&empty);

        return 0;
}
