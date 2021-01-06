#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define N 22
int maze[N][N] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1},
                  {1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1},
                  {1,0,1,1,1,1,1,0,1,0,0,1,1,1,0,1,1,1,1,1,0,1},
                  {1,0,1,0,1,0,0,0,1,1,0,1,0,1,0,0,0,0,0,0,0,1},
                  {1,0,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,1,0,1,1,1},
                  {1,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,0,1},
                  {1,0,1,0,0,0,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1},
                  {1,0,1,1,1,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1},
                  {1,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,1,1},
                  {1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,0,0,1,0,1},
                  {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1},
                  {1,0,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,0,0,1},
                  {1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1},
                  {1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,1},
                  {1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,0,1,0,1},
                  {1,0,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,1,0,1,0,1},
                  {1,0,1,0,0,0,0,1,0,0,0,1,0,1,1,1,0,0,0,1,0,1},
                  {1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1},
                  {1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1},
                  {1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1},
                  {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

struct PATH
{
   int m;//地图数组的行下标
   int n;//地图数组的列下标
   struct PATH *next;
   struct PATH *prev;
};

void dispaly()
{
    SetConsoleOutputCP(437);
    char none[] = "  ";
    int i, j;
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            if (maze[i][j] == 1)
                printf("%c", 219);
            else if (maze[i][j] == 2)
                printf("%c%c", 176, 176);
            else
                printf("  ");            
        }
        printf("\n");
    }
}

struct PATH* create(int m, int n)
{
    struct PATH *pr = (struct PATH*)malloc(sizeof(struct PATH));
    pr->m = m;
    pr->n = n;
    return pr;
}

struct PATH* walk(struct PATH *start)
{
    int m, n;
    struct PATH *p = start;
    while (p->next != NULL)
        p = p->next;
    m = p->m;
    n = p->n;
    if(maze[m+1][n] != 1 && maze[m+1][n] != 4)//walk down
    {
        p->next = create(m+1, n);
        p->next->prev = p;
        p->next->next = NULL;
        maze[m][n] = 4;
        maze[m+1][n] = 2;
    }
    else if (maze[m][n+1] != 1 && maze[m][n+1] != 4)
    {
        p->next = create(m, n+1);
        p->next->prev = p;
        p->next->next = NULL;
        maze[m][n] = 4;
        maze[m][n+1] = 2;
    }
    else if (maze[m][n-1] != 1 && maze[m][n-1] != 4)
    {
        p->next = create(m, n-1);
        p->next->prev = p;
        p->next->next = NULL;
        maze[m][n] = 4;
        maze[m][n-1] = 2;
    }
    else if (maze[m-1][n] != 1 && maze[m-1][n] != 4)
    {
        p->next = create(m-1, n);
        p->next->prev = p;
        p->next->next = NULL;
        maze[m][n] = 4;
        maze[m-1][n] = 2;
    }
    else
    {
        struct PATH *pr = p->prev;
        maze[pr->m][pr->n] = 2;
        maze[m][n] = 4;
        free(p);
        pr->next = NULL;
    }
    return start;
}







int main()
{
    int i, j, endm, endn;
    struct PATH *start = (struct PATH*)malloc(sizeof(struct PATH));
    start->next = NULL;
    dispaly();
    for(i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            if(maze[i][j] == 2)
            {
                start->m = i;
                start->n = j;
            }
            if (maze[i][j] == 3)
            {
                endm = i;
                endn = j;
            }
        }
    }
    struct PATH *p = start;
    while (p->m != endm || p->n != endn)
    {
        system("cls");
        dispaly();
        Sleep(30);
        start = walk(start);
        p = start;
        while (p->next != NULL)
        {
            p = p->next;
        }
    }
    system("cls");
    dispaly();
    return 0;
}