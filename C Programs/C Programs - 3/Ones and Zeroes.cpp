#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);

    queue <string> number;
    queue <int> remainder;

    number.push("1");
    remainder.push(1%n);

    while(true)
    {
        int current_remainder = remainder.front();
        string current_number = number.front();

        if(current_remainder == 0)
        {
            cout << current_number << '\n';
            return;
        }

        number.push(current_number + "0");
        number.push(current_number + "1");
        number.pop();

        remainder.push((current_remainder*10)%n);
        remainder.push((current_remainder*10 + 1)%n);
        remainder.pop();
    }
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
