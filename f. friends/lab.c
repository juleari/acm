#include <stdio.h>
#include <math.h>


int len2(int x, int y)
{
    return sqrt( x * x + y * y );
}

double alex(int lac, int lbc, int v, int d)
{
    return d + 60 * (lac + lbc) / v;
}

int dmit(int th, int tm, int fh, int fm)
{
    return 60 * (th + fh - 9) + tm + fm;
}

double petr(int lac, int lbc, int lab, int w, int d)
{
    double t= 60 * lab / w;
    
    if ( lac + lbc == lab )
    {
        t += d;
    }

    return t;
}

int main(int argc, char const *argv[])
{
    int xa, ya, xb, yb, xc, yc;
    int d, v;
    int th, tm, fh, fm;
    int w;
    int lac, lbc, lab;
    double a, p;

    scanf("%i%i%i%i%i%i", &xa, &ya, &xb, &yb, &xc, &yc);
    scanf("%i%i", &d, &v);
    scanf("00%02i:%02i %02i:%02i", &th, &tm, &fh, &fm);
    scanf("%i", &w);

    lac = len2(xc - xa, yc - ya),
    lbc = len2(xc - xb, yc - yb),
    lab = len2(xb - xa, yb - ya);

    a = alex(lac, lbc, v, d);
    p = petr(lac, lbc, lab, w, d);
    d = dmit(th, tm, fh, fm);

    if ( a < p )
    {
        if ( a < d ) printf("Alex\n");
        else         printf("Dmitry\n");
    }
    else
    {
        if ( p < d ) printf("Petr\n");
        else         printf("Dmitry\n");
    }

    return 0;
}