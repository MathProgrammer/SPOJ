#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_hotels, budget;
    scanf("%d %d", &no_of_hotels, &budget);

    vector <int> hotel_price(no_of_hotels + 1, 0);
    for(int i = 1; i <= no_of_hotels; i++)
        scanf("%d", &hotel_price[i]);

    long long maximum_spending = 0, current_spending = 0;
    for(int left = 1, right = 1; right <= no_of_hotels; right++)
    {
        current_spending += hotel_price[right];

        while(current_spending > budget)
        {
            current_spending -= hotel_price[left++];
        }

        maximum_spending = max(maximum_spending, current_spending);
    }

    printf("%lld\n", maximum_spending);
    return 0;
}
