#include <cstdio>

int main()
{
    int no_of_numbers;
    scanf("%d", &no_of_numbers);

    int lonely_number = 0;
    for(int i = 1; i <= no_of_numbers; i++)
    {
        int number_i;
        scanf("%d", &number_i);
        lonely_number ^= number_i;
    }

    printf("%d\n", lonely_number);
    return 0;
}
