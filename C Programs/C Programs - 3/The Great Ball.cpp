#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define all(v) (v).begin(), (v).end()

struct log{
	int time, type;
};

int compare(const log &A, const log &B)
{
	return (A.time <= B.time);
}

void solve()
{
	const int ENTRY = 0, EXIT = 1;

	int no_of_people;
	scanf("%d", &no_of_people);

	vector <log> event(2*no_of_people);

	for(int i = 0; i < no_of_people; i++)
	{
		scanf("%d %d", &event[2*i].time, &event[2*i + 1].time);

		event[2*i].type = ENTRY;
		event[2*i + 1].type = EXIT;
	}

	sort(all(event), compare);

	int no_of_inside_people = 0;
	int max_people = 0;

	for(int i = 0; i < event.size(); i++)
	{
		no_of_inside_people += (event[i].type == ENTRY ? 1 : -1);
		max_people = max(no_of_inside_people, max_people);
	}

	printf("%d\n", max_people);
}

int main()
{
	int no_of_test_cases;
	scanf("%d", &no_of_test_cases);

	while(no_of_test_cases--)
		solve();

	return 0;
}
