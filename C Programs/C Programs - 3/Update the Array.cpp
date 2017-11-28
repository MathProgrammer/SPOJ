#include <cstdio>
#include <vector>
using namespace std;

void solve()
{
	int no_of_elements, no_of_updates;
	scanf("%d %d", &no_of_elements, &no_of_updates);

	vector <int> updates_starting_here(no_of_elements + 2, 0);
	while(no_of_updates--)
	{
		int left, right, value;
		scanf("%d %d %d", &left, &right, &value);

		updates_starting_here[left + 1] += value;
		updates_starting_here[right + 2]-= value;
	}

	vector <int> element(no_of_elements + 1, 0);
	for(int i = 1; i <= no_of_elements; i++)
		element[i] = element[i - 1] + updates_starting_here[i];

	int no_of_queries;
	scanf("%d", &no_of_queries);

	while(no_of_queries--)
	{
		int i;
		scanf("%d", &i);

		printf("%d\n", element[i + 1]);
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
