#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(string &code)
{
    typedef unsigned int u_int;
    vector <long long> no_of_codes_till(code.size() + 1, 0);

    no_of_codes_till[0] = 1;
    for(u_int i = 1; i <= code.size(); i++)
    {
        if(i == 1)
        {
            if(code[i - 1] == '0')
                break;

            no_of_codes_till[i] = 1;
        }
        else
        {
            int last_digit = code[i - 1] - '0', second_last_digit = code[i - 2] - '0';

            int last_two_digits = 10*second_last_digit + last_digit;

            if(last_digit == 0)
            {
                if(second_last_digit == 1 || second_last_digit == 2)
                    no_of_codes_till[i] = no_of_codes_till[i - 2];
                else
                    break;
            }
            else
            {
                no_of_codes_till[i] = no_of_codes_till[i - 1] + (last_two_digits >= 10 && last_two_digits <= 26 ? no_of_codes_till[i - 2] : 0);
            }
        }
    }
    printf("%lld\n", no_of_codes_till[code.size()]);
}

int main()
{
    while(true)
    {
        string code;
        cin >> code;

        if(code == "0") break;

        solve(code);
    }

    return 0;
}
