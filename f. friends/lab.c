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

double petr(int lab, int w, int d)
{
    return 60 * lab / w + d;
}

int main(int argc, char const *argv[])
{
    int xa, ya, xb, yb, xc, yc;
    int d, v;
    int th, tm, fh, fm;
    int w;
    int lac, lbc, lab;
    double a, p;

    scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
    scanf("%d%d%02d:%02d %02d:%02d", &d, &v, &th, &tm, &fh, &fm);
    scanf("%d", &w);

    lac = len2(xc - xa, yc - ya),
    lbc = len2(xc - xb, yc - yb),
    lab = len2(xb - xa, yb - ya);

    a = alex(lac, lbc, v, d);

    if ( (xc - xa) * (yb - yc) == (yc - ya) * (xb - xc) ) d = 0;

    p = petr(lab, w, d);
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