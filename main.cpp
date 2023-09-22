#include "ext.hpp"
#include "ext.cpp"
#include "unit_test.cpp"

#define OUTPUTFILE "answers.txt"

#ifndef DEBUG
    #define NDEBUG
#endif


int main(int argc, char *argv[])
{

    Equation equation = {};
    Roots    roots    = {};

    #ifdef DEBUG
        Roots    test_roots = {};
    #endif

    if(check_params(argc, argv) != CORRECT)
        return PARAM_ERROR;

    FILE *finput = NULL;
    unsigned int eq_num = 0;
    const char* input_filename  = argv[1];


    if((finput = fopen(input_filename, "r"))  == NULL)
        return alert("Can't open input file\n", INPUT_ERROR);    
                                                                                                        //printf("%s\n", input_filename);

    if(fscanf(finput, "%d", &eq_num) == 0)
        return alert("Invalid input.\n", INPUT_ERROR);
                                                                                                        //printf("eq_num - %d\n", eq_num);

    #ifdef NDEBUG
        FILE *foutput = fopen(OUTPUTFILE, "w");
    #endif

    for(int i = 0; i < eq_num; i++)
    {
        #ifdef NDEBUG                                                                                         //printf("Equation %d\n", i+1);
            if(fscanf(finput, "%lf %lf %lf", &(equation.a), &(equation.b), &(equation.c)) != 3)
                return alert("Invalid input.\n", INPUT_ERROR);                                                                                   //printf("%1.1lf %1.1lf %1.1lf\n", equation.a, equation.b, equation.c);
        #else
            //printf("i = %d\n", i);
            read_test_input(&equation, &test_roots, finput);
        #endif

            if( calculate(&equation, &roots) != CORRECT )
                return alert("Calculation error.\n", COUNT_ERROR);
        
        #ifdef DEBUG
            test_attempt(&test_roots, &roots, i);
        #else
            switch (roots.num_roots)
            {
                case NO_ROOTS:
                    fprintf(foutput, "No real roots.\n");
                    break;
                case ONE_ROOT:
                    fprintf(foutput, "%.2lf\n", roots.x1);
                    break;
                case TWO_ROOTS:
                    fprintf(foutput, "%.2lf %.2lf\n", roots.x1, roots.x2);
                    break;
                case INF_ROOTS:
                    fprintf(foutput, "INF roots.\n");
                    break;
                default:
                    break;
            }
        #endif

    }
    
        fclose(finput);
    
    #ifdef NDEBUG
        fclose(foutput);

        color(GRN);
        printf("Look for the answers in \'answers.txt\' \n");
        color(STD);
    #endif



    return 0;
}
