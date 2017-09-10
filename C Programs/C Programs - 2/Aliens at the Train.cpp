#include <cstdio>
#include <vector>

using namespace std;

void solve()
{
    int no_of_stops, maximum_people_limit;
    scanf("%d %d", &no_of_stops, &maximum_people_limit);

    vector <int> no_of_people_at_stop(no_of_stops + 1);
    for(int i = 1; i <= no_of_stops; i++)
        scanf("%d", &no_of_people_at_stop[i]);

    int maximum_stops = 0, maximum_people = 0, current_people = 0;
    for(int left = 1, right = 1; right <= no_of_stops; right++)
    {
        current_people += no_of_people_at_stop[right];

        while(current_people > maximum_people_limit)
            current_people -= no_of_people_at_stop[left++];

        int current_stops = right - (left - 1);

        if(current_stops > maximum_stops)
        {
            maximum_stops = current_stops;
            maximum_people = current_people;
        }
        else if(current_stops == maximum_stops)
        {
            maximum_people = min(maximum_people, current_people);
        }
    }

    printf("%d %d\n",maximum_people, maximum_stops);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
