
void read_test_input(Equation *eq, Roots *test_rt, FILE *test_input){
    
    if(fscanf(test_input, "%lf %lf %lf %d", &eq->a, &eq->b, &eq->c, &test_rt->num_roots) != 4)
        alert("Invalid test input.\n", INPUT_ERROR);
    //printf("%lf %lf %lf %d", eq->a, eq->b, eq->c, test_rt->num_roots);
    switch (test_rt->num_roots)
    {
    case ONE_ROOT:
        assert(fscanf(test_input, "%lf", &test_rt->x1));
        break;
    case TWO_ROOTS:
        assert(fscanf(test_input, "%lf %lf", &test_rt->x1, &test_rt->x2));
        break;
    default:
        break;
    }
}

void test_attempt(Roots *test_rt, Roots *rt, int i){
    
    printf("Test %d: ", i+1);
        
    if(test_rt->num_roots != rt->num_roots)
        printf("\033[1;31mfailed\033[1;0m. Expected %d roots, but got %d\n", test_rt->num_roots, rt->num_roots);
    else 
        switch (rt->num_roots)
        {
            case 1:
                if(test_rt->x1 == rt->x1)
                    printf("\033[1;32mpassed\033[1;0m.\n");
                else
                    printf("\033[1;31mfailed\033[1;0m. Expected %lf, but got %lf\n", test_rt->x1, rt->x1);
                break;
            case 2:
                if((test_rt->x1 == rt->x1 && test_rt->x2 == rt->x2) || (test_rt->x1 == rt->x2 && test_rt->x2 == rt->x1))
                    printf("\033[1;32mpassed\033[1;0m.\n");
                else
                    printf("\033[1;31mfailed\033[1;0m. Expected %lf %lf, but got %lf %lf\n", test_rt->x1, test_rt->x2, rt->x1, rt->x2);
                break;
            default:
                    printf("\033[1;32mpassed\033[1;0m.\n");
                break;
        }       
}