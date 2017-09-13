#include <cstdio>
#include <string>
#include <iostream>

typedef unsigned int u_int;
using namespace std;

void solve()
{
    string number;
    cin >> number;

    int current_run = 1, no_of_fancy_numbers = 1;
    for(unsigned int i = 1; i < number.size(); i++)
    {
        if(number[i] == number[i - 1])
        {
            current_run++;
        }
        else
        {
            no_of_fancy_numbers *= (1 << (current_run - 1));
            current_run = 1;
        }
    }

    no_of_fancy_numbers *= (1 << (current_run - 1));

    printf("%d\n", no_of_fancy_numbers);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
