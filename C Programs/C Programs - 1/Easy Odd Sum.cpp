#include <cstdio>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int first = (a%2 == 0 ? a + 1 : a);
	int last = (b%2 == 0 ? b - 1 : b);

	int no_of_odd_numbers = (last - first)/2 + 1;
	int average = (first + last)/2;

	long long sum = no_of_odd_numbers*1LL*average;

	printf("%lld\n", sum);
	return 0;
}
