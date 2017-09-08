#include <cstdio>

int get_term(int term)
{
    switch(term)
    {
        case 1 : return 1;
        case 2 : return 3;
        case 3 : return 2;
        case 4 : return -1;
        case 5 : return -3;
    }
}

int main()
{
    const int NO_OF_TERMS = 6;
    int sum_till[NO_OF_TERMS] = {0};

    for(int i = 1; i < NO_OF_TERMS; i++)
        sum_till[i] = sum_till[i - 1] + get_term(i);

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        long long n;
        scanf("%lld", &n);

        printf("%d\n", sum_till[n%6]);
    }

    return 0;
}
