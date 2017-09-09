#include <cstdio>

int main()
{
    const int ORIGIN_X = 25, ORIGIN_Y = 25, MAX_STEPS = 15, MAX_NEIGHBOURS = 6;
    int x_distance[MAX_NEIGHBOURS] = {-1, -1, 0, 1, 1, 0};
    int y_distance[MAX_NEIGHBOURS] = {0, 1, 1, 0, -1, -1};

    long long no_of_homecoming_walks[MAX_STEPS][2*ORIGIN_X][2*ORIGIN_Y] = {0};

    no_of_homecoming_walks[0][ORIGIN_X][ORIGIN_Y] = 1;

    for(int step = 1; step < MAX_STEPS; step++)
    {
        for(int x = 1; x < 2*ORIGIN_X; x++)
        {
            for(int y = 1; y < 2*ORIGIN_Y; y++)
            {
                for(int neighbour_no = 0; neighbour_no < MAX_NEIGHBOURS; neighbour_no++)
                {
                    int neighbour_x = x + x_distance[neighbour_no];
                    int neighbour_y = y + y_distance[neighbour_no];
                    no_of_homecoming_walks[step][x][y] += no_of_homecoming_walks[step - 1][neighbour_x][neighbour_y];
                }
            }
        }
    }

    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
    {
        int no_of_steps;
        scanf("%d", &no_of_steps);

        printf("%lld\n", no_of_homecoming_walks[no_of_steps][ORIGIN_X][ORIGIN_Y]);
    }

    return 0;
}
