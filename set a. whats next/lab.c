#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a1 = 1, a2 = 1, a3 = 1, d;

    scanf("%d%d%d", &a1, &a2, &a3);

    while ( a1 != a2 && a2 != a3 && a3 != 0 )
    {
        d = a2 - a1;
        if ( a3 - a2 == d ) { printf("AP %d\n", a3 + d); }
        else
        {
            d = a2 / a1;
            printf("GP %d\n", a3 * d);
        }

        scanf("%d%d%d", &a1, &a2, &a3);
    }

    return 0;
}