#define square(x) x*x

int check_params(int argc, char *argv[])
{
    if(argc != 2) 
        return alert("Invalid arguments.", PARAM_ERROR);  
    else
        return CORRECT;
}


void color(const char* color)
{
    printf(color);
}


int alert(const char* text, int error)
{
    color(RED);
    printf(text);
    color(STD);
    return error;
}

int calculate(Equation *eq, Roots *rt)
{
    double a = eq->a;
    double b = eq->b;
    double c = eq->c;
    double d = square(b) - 4*a*c;

    if(a == 0){
        if(b == 0) 
            rt->num_roots = c == 0 ? INF_ROOTS : NO_ROOTS;
        else
        {
            rt->num_roots = ONE_ROOT;
            rt->x1        = -c/b;
        }
        return CORRECT;
    }

    if(d < 0)
    {
        rt->num_roots = NO_ROOTS;   
    }
    else if(d == 0)
    {
        rt->num_roots = ONE_ROOT;
        rt->x1         = -b/(2*a);
    }
    else if(d > 0)
    {
        rt->num_roots = TWO_ROOTS;
        rt->x1        = (-b-sqrt(d))/2/a;
        rt->x2        = (-b+sqrt(d))/2/a;
        return CORRECT; 
    } else return COUNT_ERROR;

    return CORRECT;
}