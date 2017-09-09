#include <cstdio>

int main()
{
    while(true)
    {
        int no_of_squares;
        scanf("%d", &no_of_squares);

        if(no_of_squares == 0) break;

        int answer = (no_of_squares*(no_of_squares + 1)*(2*no_of_squares + 1))/6;
        printf("%d\n", answer);
    }
    return 0;
}
