#include <cstdio>

void semi_circle_area(double circumference)
{
    const double PI = 3.1415926;

    double area = (circumference*circumference)/(2*PI);
    printf("%.2lf\n", area);
}

int main()
{
    while(true)
    {
        double circumference;
        scanf("%lf", &circumference);

        if(circumference == 0) break;

        semi_circle_area(circumference);
    }

    return 0;
}
