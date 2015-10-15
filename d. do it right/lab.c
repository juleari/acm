#include <stdio.h>
#include <math.h>

int sqrtc( int a, int b )
{
    return sqrt( a * a + b * b );
}

int sqrtb( int c, int a )
{
    return sqrt( c * c - a * a );
}

char* right(int a, int b)
{
    int c;

    c = sqrtc( a, b );

    if ( c * c == a * a + b * b ) 
    {
        return "YES";
    }

    if ( a > b ) 
    {
        c = sqrtb( a, b );
        if ( c * c == a * a - b * b ) 
        {
            return "YES";
        }
    }
    else
    {
        c = sqrtb( b, a );
        if ( c * c == b * b - a * a ) 
        {
            return "YES";
        }
    }

    return "NO";
}

int main()
{
    int a, b;

    scanf( "%d%d", &a, &b );

    printf("%s\n", right(a, b));

    return 0;
}