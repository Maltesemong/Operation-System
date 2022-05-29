#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *getSquare()
{
        int i;
        int s;

        printf(">>");
        scanf("%d", &s);
        int result = 1;
        int *sqr;

        for (i = 0; i < 2; i++)
        {
                result = result * s;
        }
        *sqr = result;
        return (void *)sqr;
}

int main()
{
        pthread_t tid;
        int *sqr;
        pthread_create(&tid, NULL, getSquare, (void *)&tid);
        pthread_join(tid, (void **)&sqr);
        printf("%d\n", *sqr);
        return 0;
}
