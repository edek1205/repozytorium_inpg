#include<stdio.h>
#include<stdlib.h>
 
struct FIFO
{
    struct el_FIFO* pocz;
    struct el_FIFO* kon;
};
 
struct el_FIFO
{
    int x;
    struct el_FIFO* nast;
};
 
struct FIFO* attach(struct FIFO *top, int el)
{
    struct el_FIFO * new_el_FIFO=(struct el_FIFO*)malloc(sizeof(struct el_FIFO));
    new_el_FIFO->x=el;
    if(top->kon==NULL)
    {
        new_el_FIFO->nast=NULL;
        top->kon=new_el_FIFO;
        top->pocz=new_el_FIFO;
    }
    else
    {
        new_el_FIFO->nast=NULL;
        top->pocz->nast=new_el_FIFO;
        top->pocz=new_el_FIFO;
    }
    return top;
}
 
struct FIFO* detach(struct FIFO *top, int *el)
{
    struct el_FIFO * temp;
    if(top->kon!=NULL)
    {
        *el=top->kon->x;
        temp=top->kon;
        top->kon=temp;
        free(top->kon);
        return top;
    }
    else
    {
        return NULL;
    }
}
 
int top_el(struct FIFO *top, int *el)
{
    if (top!=NULL)
    {
        *el=top->kon->x;
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int main()
{
    struct el_FIFO * FIFO=(struct el_FIFO*)malloc(sizeof(struct el_FIFO));
    struct el_LIFO *top_FIFO=NULL;
    struct FIFO *kolejka_FIFO=NULL;
 
    kolejka_FIFO=attach(kolejka_FIFO,7);
    kolejka_FIFO=attach(kolejka_FIFO,12);
    kolejka_FIFO=attach(kolejka_FIFO,25);
 
    int t;
    if (top_el(kolejka_FIFO,&t)) printf("Wierzcholek: %d\n",kolejka_FIFO->pocz->x);
    else printf("Kolejka pusta.\n");
 
    int d;
    kolejka_FIFO=detach(kolejka_FIFO,&d);
 
    printf("Usunieto: %d\n",d);
    if (top_el(kolejka_FIFO,&t)) printf("Wierzcholek: %d\n",kolejka_FIFO->pocz->x);
    else printf("Kolejka pusta.\n");
    return 0;
}