#include <cstdio>
#include <vector>

using namespace std;

void get(vector <long long> &number_of_numbers)
{
    const int MAX_DIGITS = 64, MAX_DIGIT_VALUE = 9;
    long long no_of_numbers_with_last_digit[MAX_DIGITS + 1][MAX_DIGIT_VALUE + 1];

    for(int i = 1; i <= MAX_DIGITS; i++)
    {
        for(int last_digit = 0; last_digit <= MAX_DIGIT_VALUE; last_digit++)
        {
            if(i == 1 && last_digit == 0)
            {
                no_of_numbers_with_last_digit[i][last_digit] = 1;
            }
            else if(i == 1)
            {
                no_of_numbers_with_last_digit[i][last_digit] = no_of_numbers_with_last_digit[i][last_digit - 1] + 1;
            }
            else if(last_digit == 0)
            {
                no_of_numbers_with_last_digit[i][last_digit] = no_of_numbers_with_last_digit[i - 1][last_digit];
            }
            else
            {
                no_of_numbers_with_last_digit[i][last_digit] = no_of_numbers_with_last_digit[i][last_digit - 1] +
                                                                   no_of_numbers_with_last_digit[i - 1][last_digit];
            }
        }
        number_of_numbers[i] = no_of_numbers_with_last_digit[i][MAX_DIGIT_VALUE];
    }
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    const int MAX_DIGITS = 64;
    vector <long long> number_of_numbers(MAX_DIGITS + 1, 0);

    get(number_of_numbers);

    while(no_of_test_cases--)
    {
        int test_i, number_of_digits;
        scanf("%d %d", &test_i, &number_of_digits);

        printf("%d %lld\n", test_i, number_of_numbers[number_of_digits]);
    }
    return 0;
}
