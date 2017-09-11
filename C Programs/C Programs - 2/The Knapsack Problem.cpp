#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int maximum_capacity, no_of_items;
    scanf("%d %d", &maximum_capacity, &no_of_items);

    vector <int> weight_of(no_of_items + 1);
    vector <int> value_of(no_of_items + 1);
    for(int i = 1; i <= no_of_items; i++)
        scanf("%d %d", &weight_of[i], &value_of[i]);

    typedef vector <int> v_int;
    vector <v_int> maximum_value_till(no_of_items + 1, v_int(maximum_capacity + 1, 0));

    for(int i = 1; i <= no_of_items; i++)
    {
        for(int remaining_weight = 0; remaining_weight <= maximum_capacity; remaining_weight++)
        {
            maximum_value_till[i][remaining_weight] = maximum_value_till[i - 1][remaining_weight];

            if(weight_of[i] <= remaining_weight)
                maximum_value_till[i][remaining_weight] = max(maximum_value_till[i][remaining_weight],
                                                              maximum_value_till[i - 1][remaining_weight - weight_of[i]] + value_of[i]);
        }
    }

    printf("%d\n", maximum_value_till[no_of_items][maximum_capacity]);
    return 0;
}
