#include <cstdio>
#include <vector>

using namespace std;

typedef vector <long long> v_long;

void solve(int test_i, int no_of_rows)
{
    const int NO_OF_COLUMNS = 3, oo = 1e9;
    vector <v_long> minimum_till(no_of_rows + 2, v_long(NO_OF_COLUMNS + 2));

    for(int row = 1; row <= no_of_rows; row++)
    {
        int first, second, third;
        scanf("%d %d %d", &first, &second, &third);

        if(row == 1)
        {
            minimum_till[row][1] = oo;
            minimum_till[row][2] = second;
            minimum_till[row][3] = second + third;
        }
        else
        {
            minimum_till[row][1] = first + min(minimum_till[row - 1][1], minimum_till[row - 1][2]);
            minimum_till[row][2] = second + min( min(minimum_till[row][1], minimum_till[row - 1][1]),
                                                 min(minimum_till[row - 1][2], minimum_till[row - 1][3]));
            minimum_till[row][3] = third + min(minimum_till[row][2], min(minimum_till[row - 1][2], minimum_till[row - 1][3]));
        }
    }

    printf("%d. %lld\n", test_i, minimum_till[no_of_rows][2]);
}

int main()
{
    int no_of_rows;

    for(int test_i = 1; scanf("%d", &no_of_rows); test_i++)
    {
        if(no_of_rows == 0) break;

        solve(test_i, no_of_rows);
    }

    return 0;
}
