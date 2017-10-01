#include <cstdio>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> element(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &element[i]);

    int possible_to_equalise = true;
    int difference = element[1];
    for(int i = 2; i < no_of_elements; i++)
    {
        element[i] -= difference;

        if(element[i] < 0)
        {
            possible_to_equalise = false;
            break;
        }

        difference = element[i];
    }

    if(difference != element[no_of_elements] || no_of_elements == 1)
        possible_to_equalise = false;

    printf(possible_to_equalise ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
