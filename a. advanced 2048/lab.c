#include <stdio.h>
#include <stdlib.h>

unsigned short **h;

unsigned short getpow(int v)
{
    unsigned short p = 1;
    while ( v != 2 )
    {
        v >>= 1;
        p++;
    }

    return p;
}

long int gameIter( char c, int n )
{
    long int s = 0, e = 1;
    unsigned short l, cur;
    int i, j, k;

    switch (c)
    {
        case 'L': 
            for (i = 0; i < n; i++)
            {
                l = 0;
                k = 0;

                for (j = 0; j < n; j++)
                {
                    cur = h[i][j];
                    if ( cur > 0 )
                    {
                        h[i][j] = 0;
                        if ( cur == l )
                        {
                            h[i][k++] = ++l;
                            s        += e << l;
                            l         = 0;
                        }
                        else
                        {
                            if ( l > 0 ) { k++; }
                            h[i][k] = cur;
                            l         = cur;
                        }
                    }
                }
            }
            break;
        case 'R':
            for (i = 0; i < n; i++)
            {
                l = 0;
                k = n - 1;

                for (j = n - 1; j >= 0; j--)
                {
                    cur = h[i][j];
                    if ( cur > 0 )
                    {
                        h[i][j] = 0;
                        if ( cur == l )
                        {
                            h[i][k--] = ++l;
                            s        += e << l;
                            l         = 0;
                        }
                        else
                        {
                            if ( l > 0 ) { k--; }
                            h[i][k] = cur;
                            l       = cur;
                        }
                    }
                }
            }
            break;
        case 'U':
            for (j = 0; j < n; j++)
            {
                l = 0;
                k = 0;

                for (i = 0; i < n; i++)
                {
                    cur = h[i][j];
                    if ( cur > 0 )
                    {
                        h[i][j] = 0;
                        if ( cur == l )
                        {
                            h[k++][j] = ++l;
                            s        += e << l;
                            l         = 0;
                        }
                        else
                        {
                            if ( l > 0 ) { k++; }
                            h[k][j] = cur;
                            l         = cur;
                        }
                    }
                }
            }
            break;
        default :
            for (j = 0; j < n; j++)
            {
                l = 0;
                k = n - 1;

                for (i = n - 1; i >= 0; i--)
                {
                    cur = h[i][j];
                    if ( cur > 0 )
                    {
                        h[i][j] = 0;
                        if ( cur == l )
                        {
                            h[k--][j] = ++l;
                            s        += e << l;
                            l         = 0;
                        }
                        else
                        {
                            if ( l > 0 ) { k--; }
                            h[k][j] = cur;
                            l         = cur;
                        }
                    }
                }
            }
            break;
    }

    return s;
}

void printH( int n )
{
    int i, j;

    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%hi ", h[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j, n, k, v, x, y, l;
    char c;
    long int score = 0;

    scanf("%d%d", &n, &k);

    h = (unsigned short **)malloc( n * sizeof(unsigned short*) );

    for (i = 0; i < n; i++) 
    {
        h[i] = (unsigned short *)malloc( n * sizeof(unsigned short) );
        for (j = 0; j < n; j++) {
            h[i][j] = 0;
        }
    }

    for (i = 0; i < k; i++)
    {
        scanf("%d%d%d", &v, &x, &y);
        h[ x - 1 ][ y - 1 ] = getpow(v);
    }

    scanf("%d", &l);

    for (i = 0; i < l; i++)
    {
        scanf("\n%c%d%d%d", &c, &v, &x, &y);
        score += gameIter(c, n);

        // printH(n);

        h[ x - 1 ][ y - 1 ] = getpow(v);
    }

    printf("%ld\n", score);

    free(h);

    return 0;
}
