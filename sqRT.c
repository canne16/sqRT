#include <math.h>
#include <stdio.h>
#include <ctype.h>

void prompt();
void menu();
double square();
double linear();
void makechoice();
void clearbuf();


int main()
{
    prompt();
    menu();

    makechoice();
     
    return 0;
}


void makechoice()
{
    
    int i = 0; 
    
    if(scanf("%d", &i) != 0)
    {

        switch (i)
        {
        case 1:
            square();
            line();
            menu();
            makechoice();
            break;
        case 2:
            linear();
            line();
            menu();
            makechoice();
            break;
        case 3:
            break;
        default:
            printf("\n\tIncorrect choice! ;[ Try better.\n\t");
            clearbuf();
            makechoice();
            break;
        }

    } else{
        printf("\n\tMust be a number.\n\t");
        clearbuf();
        makechoice();
    }
}

double square(){
    
    double A, B, C;
    A = 0; B = 0; C = 0;
    double D = 0;
    
    line();

    printf("\n\n\tThe format is:\tax^2 + bx + c = 0.\n");
    printf("\n\tNumbers a, b and c must be decimal or with floating point\n");
    printf("\tFor example: 10 -1 3.14\n\t");
    printf("\n\tEnter a b c: \t");
    if(scanf("%lf %lf %lf", &A, &B, &C) == 3)
    {
        
        clearbuf();

        if(A == 0){
            printf("\n\tThe equation is (or almost is) linear :/, please switch in menu.\n");
            return 0;
            }

        printf("\n\tThe equation is %.1f*x^2%+.1f*x%+.1f = 0\n", A, B, C);

        D = B*B - 4*A*C;
        
        printf("\n\tD = %.3f\n", D);
        
        if(D >= 0){
            double x1 = (-B - sqrt(D))/(2*A);
            double x2 = (-B + sqrt(D))/(2*A);
            printf("\tx1 = %+.3f\n", x1);
            printf("\tx2 = %+.3f\n\n", x2);
            return 0;
        } else {
            printf("\tNo solution found, D < 0\n\n");
            return 0;
        }

    } else {

        line();

        printf("\n\tIncorrect input! Read instructions.\n");
        clearbuf();
        square();
    }
    return 0;
};


double linear(){

    double A, B;
    A = 0; B = 0;

    line();

    printf("\n\n\tThe format is:\tax + b = 0.\n");
    printf("\n\tNumbers a and b must be decimal or with floating point\n");
    printf("\tFor example: 6.602 -4\n\t");
    printf("\n\tEnter a b: \t");
    if(scanf("%lf %lf", &A, &B) == 2){
        
        clearbuf();
        
        if(A == 0){
            printf("\n\tThe equation is incorrect, A = 0.\n");
            return 0;
        }

        printf("\n\tThe equation is %.1f*x%+.1f = 0\n", A, B);

        double x = -B/A;
        printf("\tx = %+.3f\n\n", x);
        
        return 0;

    } else {
        
        line();

        printf("\n\tIncorrect input! Read instructions.\n");
        clearbuf();
        linear();

    }
    return 0;


};

void prompt()
{

    line();
    
    printf("\n\t%s", "sqRT.exe solves square eqations. The format is following:\tax^2 + bx + c = 0.\n"
           "\n\tTo continue press any key...\n");

    line();

    while (getchar() != '\n')
        continue;    

}

void clearbuf(){
    int c;
    while ( (c = getchar()) != '\n' && c != EOF ) { };
}

void line()
{
    for (int i = 0; i < 120; i++)
        putchar('_');
}

void menu()
{
    printf("\n");
    printf("\t(%d) - %s", 1, "solve a square equation\n");
    printf("\t(%d) - %s", 2, "solve a linear equation\n");
    printf("\t(%d) - %s", 3, "exit\n");
    printf("\n\t");

}