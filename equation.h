#include "TXLib.h"
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <ctype.h>

/// Set of states of solveSquare
enum SOLVESTATUS
{
    NO_ROOTS       = 0,  ///< Shows that there are no roots
    ONE_ROOT       = 1,  ///< Shows that there are 1 root
    TWO_ROOTS      = 2,  ///< Shows that there are 2 roots
    INFINITE_ROOTS = 3,  ///< Shows that there are infinite roots
    TEST           = 4,  ///< Starts tests
    KEYBOARD       = 5   ///< Input by hands
};

const double EPSILON = 0.001; ///< Shows double error. Determinated by math.

/**
    Solve a quadratic equation ax2 + bx + c = 0

    @param [in]   a - quadratic coefficient
    @param [in]   b - quadratic coefficient
    @param [in]   c - quadratic coefficient
    @param [out] x1 - the 1st root
    @param [out] x2 - the 2nd root

    @return Number of roots: 0 / 1 / 2 / infinite

*/

int solveSquare (double a, double b, double c,
                 double* x1, double* x2);

/**
    Solve a linear equation kx + b = 0

    @param [in]   k - linear coefficient
    @param [in]   b - linear coefficient
    @param [out] x1 - the 1st root

    @return Number of roots: 0 / 1 / infinite

*/

int solveLinear (double k, double b, double* x1);

/**
    Checks equality of doubles

    @param [in] value    - the 1st number
    @param [in] valueref - the 2nd number

    @return Result: true/false

    @warning If both numbers are NAN then return TRUE!

*/

int isEqual (double value, double valueref);

/**
    Checks if  adouble is NULL

    @param [in] value - number

    @return Result: true/false

*/

int IsZero (double value);


/**
    For tests solveSquare

    @param [in] testNum   - shows test's number
    @param [in] a         - quadratic coefficient
    @param [in] b         - quadratic coefficient
    @param [in] c         - quadratic coefficient
    @param [in] x1ref     - expected the 1st root
    @param [in] x2ref     - expected the 2nd root
    @param [in] nRootsref - expected number of roots

    @return Test status: succes/failure

*/

int UnitTest (int testNum, double a, double b, double c, double x1ref, double x2ref, int nRootsref);


/**
    Start UnitTest

    @return Number of the succesful tests

*/

int RunUnitTest ();


/**
    Clean buffer
*/

void cleanBuffer ();

/**
    Analysis number of roots

    @param [in] nRoots - number of roots
    @param [in] x1     - the 1st root
    @param [in] x2     - the 2nd root

*/

void printSquare (int nRoots, double x1, double x2);

/**
    Checks the user for adeuacy

    @param [in]   a - quadratic coefficient
    @param [in]   b - quadratic coefficient
    @param [in]   c - quadratic coefficient

*/

void inputValues (double* a, double* b, double* c);


