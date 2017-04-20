#include <stdio.h>
#include <stdlib.h>
struct element {
    int wartosc;
    struct element * poprzedni;
    struct element * nastepny;
}*pierwszy, *ostatni;
 
void stworzyc_Liste(int n);
void drukowac_Liste();
 
int main()
{
    int n, wartosc, wybor=1;
    pierwszy = NULL;
    ostatni = NULL;
    while(wybor != 0)
    {
        printf("============================================\n");
        printf("PROGRAM LISTA DWUKIERUNKOWA\n");
        printf("============================================\n");
        printf("1. Stworzyc Liste\n");
        **printf("2. Usunac Liste\n");**
        printf("3. Wydrukowac liste\n");
        printf("0. Wyjsc\n");
        printf("------------------------------------------\n");
        printf("Wprowadz swoj wybor : ");
        scanf("%d", &wybor);
 
        switch(wybor)
        {
            case 1:
                printf("Wprowadz calkowita liczbe elementow w liscie: ");
                scanf("%d", &n);
                stworzyc_Liste(n);
                break;
            case 2:
 
            case 3:
                drukowac_Liste();
                break;
            case 0:
                break;
            default:
                printf("Blad! Niewlasciwy wybor. Prosze wybrac pomiedzy 0-5");
        }
        printf("\n\n\n\n\n");
    }
    return 0;
}
void stworzyc_Liste(int n) {
    int i;
    int wartosc;
    struct element *nowyElement;
    if (n >= 1) {
        pierwszy = (struct element *)malloc(sizeof(struct element));
        printf("Wprowadz wartosc dla pierwszego elementu: ");
        scanf("%d", &wartosc);
        pierwszy->wartosc = wartosc;
        pierwszy->poprzedni = NULL;
        pierwszy->nastepny = NULL;
        ostatni = pierwszy;
        for (i=2; i<=n; i++) {
            nowyElement = (struct element *)malloc(sizeof(struct element));
            printf("Wprowadz wartosc dla %d elementu: ", i);
            scanf("%d", &wartosc);
            nowyElement->wartosc = wartosc;
            nowyElement->poprzedni = ostatni; 
            nowyElement->nastepny = NULL;
            ostatni->nastepny = nowyElement; 
            ostatni = nowyElement; 
        }
        printf("\nLISTA DWUKIERUNKOWA POMYSLNIE STWORZONA\n");
    }
}
void drukowac_Liste() {
    struct element * tymczasowy;
    int n = 1;
 
    if (pierwszy == NULL) {
        printf("Lista jest pusta.\n");
    } else {
        tymczasowy = pierwszy;
        printf("Wartosci w liscie:\n");
        while (tymczasowy != NULL) {
            printf("WARTOSC %d elementu = %d\n", n, tymczasowy->wartosc);
            n++;
            tymczasowy = tymczasowy->nastepny;
        }
    }
} ```