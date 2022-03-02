#include "equation.h"

int main (void)
{
    printf ("Start test? Please put y/n\n");

    char ch = 0;
    scanf ("%c", &ch);

    if (ch == 'y')
    {
        int nRight = RunUnitTest ();
        printf ("%d", nRight);

        return 0;
    }

    printf ("Enter a, b, c in ax^2 + bx + c = 0\n");

    double a = NAN, b = NAN, c = NAN;

    inputValues (&a, &b, &c);

    double x1 = NAN, x2 = NAN;

    int nRoots = solveSquare (a, b, c, &x1, &x2);

    printSquare (nRoots, x1, x2);
}