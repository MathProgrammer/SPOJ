#include <cstdio>
#include <cstring>

const int MAX_N = (1 << 20) + 1, MAX_STUDENTS = 21;
int population_count[MAX_N];
long long no_of_assignments[MAX_STUDENTS][MAX_N];

void precompute()
{
    population_count[0] = 0;

    for(int i = 1; i < MAX_N; i++)
        population_count[i] = population_count[i >> 1] + (i%2);
}

int bit_set(int mask, int position)
{
    position--;
    return (mask & (1 << position) );
}

int one_bit_unset(int mask, int position)
{
    position--;
    return (mask^(1 << position) );
}

void solve()
{
    int no_of_students;
    scanf("%d", &no_of_students);

    int likes[no_of_students + 1][no_of_students + 1];
    for(int i = 1; i <= no_of_students; i++)
        for(int j = 1; j <= no_of_students; j++)
            scanf("%d", &likes[i][j]);

    memset(no_of_assignments, 0, sizeof(no_of_assignments));
    no_of_assignments[0][0] = 1;

    for(int i = 1; i <= no_of_students; i++)
    {
        for(int mask = 1; mask < (1 << no_of_students); mask++)
        {
            if(population_count[mask] == i)
            {
                for(int j = 1; j <= no_of_students; j++)
                {
                    if(bit_set(mask, j) && likes[i][j])
                        no_of_assignments[i][mask] += no_of_assignments[i - 1][one_bit_unset(mask, j)];
                }
            }
        }
    }

    printf("%lld\n", no_of_assignments[no_of_students][(1 << no_of_students) - 1]);
}

int main()
{
    precompute();

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
