#include <cstdio>
#include <cstring>

using namespace std;

#define max(a, b) (a > b ? a : b)

const int MAX_HEALTH = 1000 + 10, MAX_ARMOUR = 1000 + 10;
int maximum_survival_time[MAX_HEALTH][MAX_ARMOUR];

int get_max_survival_time(int health, int armour)
{
    if(health <= 0 || armour <= 0)
    {
        return -1;
    }

    if(maximum_survival_time[health][armour] == -1)
        maximum_survival_time[health][armour] = 2 + max(get_max_survival_time(health - 2,armour - 8), get_max_survival_time(health - 17, armour + 7));

    return maximum_survival_time[health][armour];
}

void solve()
{
    int health, armour;
    scanf("%d %d", &health, &armour);

    int max_surival_time = get_max_survival_time(health, armour);

    printf("%d\n", max_surival_time);
}

int main()
{
    memset(maximum_survival_time, -1, sizeof(maximum_survival_time));

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
