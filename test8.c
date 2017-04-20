#include <stdio.h>
#include <stdlib.h>
 
int horner(int wspol[], int stop, int x)
{
    if (stop == 0)
        return wspol[0];
    else
        return x * horner(wspol, stop - 1, x) + wspol[stop];
}
 
int main(void)
{
 
    int n;
 
    puts("Podaj stopien wielom.:");
    scanf("%d", &n);
    int* tab = (int*)malloc((n + 1) * sizeof(int));
    int i, x;
    puts("Podaj wspolczynnki wielom.:");
    for (i = 0; i <= n; ++i)
        tab[i] = scanf("%d", tab + i);
    puts("Podaj x:");
    scanf("%d", &x);
    printf("%d", horner(tab, n, x));
 
    free(tab);
 
    return 0;
}