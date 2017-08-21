#include <cstdio>
#include <vector>

#define max_3(a, b, c) max(a, max(b, c))
using namespace std;

void solve()
{
    int no_of_rows, no_of_columns;
    scanf("%d %d", &no_of_rows, &no_of_columns);

    typedef vector <int> v_int;
    vector <v_int> maximum_stones_in_path_ending_at(no_of_rows + 1, v_int(no_of_columns + 2, 0));

    int maximum_stones_possible = 0;
    for(int row = 1; row <= no_of_rows; row++)
    {
        for(int column = 1; column <= no_of_columns; column++)
        {
            int stones_i;
            scanf("%d", &stones_i);

            int maximum_till_here = max_3(maximum_stones_in_path_ending_at[row - 1][column], maximum_stones_in_path_ending_at[row - 1][column - 1],
                                          maximum_stones_in_path_ending_at[row - 1][column + 1]);

            maximum_stones_in_path_ending_at[row][column] = stones_i + maximum_till_here;

            maximum_stones_possible = max(maximum_stones_possible, maximum_stones_in_path_ending_at[row][column]);
        }
    }

    printf("%d\n", maximum_stones_possible);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
