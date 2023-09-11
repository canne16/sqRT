#include <math.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define STD "\033[1;0m"
#define BLK "\033[1;30m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYN "\033[1;36m"
#define WHT "\033[1;37m"

enum NUM_ROOTS
{
    INF_ROOTS = -1,
    NO_ROOTS  = 0,
    ONE_ROOT  = 1,
    TWO_ROOTS = 2
};


enum ERROR_CODE
{
    CORRECT         = 0,
    PARAM_ERROR     = 1,
    OPEN_FILE_ERROR = 2,
    COUNT_ERROR     = 3,
    INPUT_ERROR     = 4
};


typedef struct
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
} Equation;


typedef struct
{
    int num_roots = -1;
    double x1     = NAN;
    double x2     = NAN;
} Roots;


Roots* calculate       (Equation *eq);
void   color           (const char* color);
int    check_params    (int argc, char *argv[]);
int    unit_test       ();
int    alert           (const char* text, int error);
void   read_test_input (Equation *eq, Roots *test_rt, FILE *test_input);
void   test_attempt    (Roots *test_rt, Roots *rt, int i);
