#include "equation.h"


int solveSquare (double a, double b, double c,
                 double* x1, double* x2)
{
    assert (std::isfinite (a));
    assert (std::isfinite (b));
    assert (std::isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (IsZero (a))
    {

        int nSolutions = solveLinear (b, c, x1);

        return nSolutions;
    }

    else // if (a != 0)
    {
        double d = b*b - 4*a*c;

        if (IsZero (d))
        {
            *x1 = -b / (2*a);
            return ONE_ROOT;
        }
        else if (d < 0)
        {
            return NO_ROOTS;
        }
        else
        {
            *x1 = (-b - sqrt (d)) / (2*a);
            *x2 = (-b + sqrt (d)) / (2*a);

            return TWO_ROOTS;
        }
    }
}


int solveLinear (double k, double b, double* root)
{
    assert (std::isfinite (k));
    assert (std::isfinite (b));

    assert (root != NULL);

    *root = NAN;

    if (IsZero (k))
        {
            if (IsZero (b))
                return INFINITE_ROOTS;
            else
                return NO_ROOTS;
        }
    else // if (k != 0)
        {
            *root = -b/k;
            return ONE_ROOT;
        }
}


int IsZero (double value)    // IsZero (0.00001) = 0
                                                      // IsZero (0.00001, 0.01) = 1
{
    assert (std::isfinite (value));

    return (isEqual(value, 0));
}


int isEqual (double value, double valueref)
{
    if ((std::isnan(value)) && (std::isnan(valueref))) return 1;

    return (fabs (value - valueref) < EPSILON);
}


int UnitTest (int testNum, double a, double b, double c, double x1ref, double x2ref, int nRootsref)
{
    assert (std::isfinite (a));
    assert (std::isfinite (b));
    assert (std::isfinite (c));
    assert (std::isfinite (nRootsref));

    double x1 = NAN, x2 = NAN;

    int nRoots = solveSquare (a, b, c, &x1, &x2);

    if ((nRoots == nRootsref) && ((isEqual (x1, x1ref) && isEqual (x2, x2ref)) || (isEqual (x1, x2ref) && isEqual (x2, x1ref))))
    {
        printf ("Test #%d - Success\n", testNum);
        return 1;
    }
    else
    {
        printf("Test #%d - FAILED:\n"
               "         %3d, %3g, %3g\n"
               "Expected %3d, %3g, %3g\n",
               testNum, nRoots, x1, x2, nRootsref, x1ref, x2ref);
        return 0;
    }
}


int RunUnitTest ()
{
    const int test_cnt = 10;
    int k = 0;
    int testNum[test_cnt] = { 1,   2,   3,   4,   5,   6,   7,    8,      9,  10};
    int a[test_cnt]       = { 1,   1,  50,   0,   0,   0,   1,    2,      3,   1};
    int b[test_cnt]       = { 5,   2,   6,   6,   0,   0,  17,   -9,    -11,   4};
    int c[test_cnt]       = {-6,   1,  30,  30,  30,   0, -18,    7,      4,   4};
    double x1[test_cnt]   = {-6,  -1, NAN,  -5, NAN, NAN, -18,  3.5, 0.4093,  -2};
    double x2[test_cnt]   = { 1, NAN, NAN, NAN, NAN, NAN,   1,    1, 3.2573, NAN};
    int nRoots[test_cnt]  = { 2,   1,   0,   1,   0,   3,   2,    2,      2,   1};

    for (int i = 0; i < test_cnt; ++i)
    {
        if (UnitTest (testNum[i], a[i], b[i], c[i], x1[i], x2[i], nRoots[i])) ++k;
    }

    printf ("Number of succesful test:\n");
    return k;
}


void cleanBuffer ()
{
    while (getchar() != '\n') {;}
}


void printSquare (int nRoots, double x1, double x2)
{
    assert (std::isfinite (nRoots));

    switch (nRoots)
      {
      case NO_ROOTS :
        printf ("No roots\n");
        break;

      case ONE_ROOT :
        printf ("x = %g\n", x1);
        break;

      case TWO_ROOTS :
        printf ("x1 = %g, x2 = %g\n", x1, x2);
        break;

      case INFINITE_ROOTS :
        printf ("Any numbers\n");
        break;

      default:
        printf ("main (void) : ERROR : nRoots = %d\n", nRoots);
      }
}


void inputValues (double* a, double* b, double* c)
{
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);

    bool flag = false;
    while (!flag)
    {
        if (scanf ("%lg %lg %lg", a, b, c) < 3)
        {
            printf ("Bad values\n");
            cleanBuffer ();
        }
        else
        {
            flag = true;
        }
    }
}

