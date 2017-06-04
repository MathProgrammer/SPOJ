#include <stdio.h>

/*The question is to find Z(n) where Z(n) is a function that maps n to the number of 0's at the end of n factorial.
The reasoning is simple. The number of 0's at the corresponds with the highest power of 10 that divides it.
10 occurs whenever 5 and 2 occur in n!. So, the exponent of 10 in n! is min{ exp(2), exp(5) } where exp(p) denoted
the exponent of p in the prime factorisation of n!
However, we can rest assured that the power of five will always be less than the power of 2 in n! (heuristically, because
the multiples of 2 occur more frequently). It can be proven through induction.
In general if b = p_1^{a_1}p_2^{a_2}...p_n^{a_n}, in it's prime factorisation, and if p_n is the greatest prime,
then the number of zeroes in z! in base b the number of time p_n occurs in the prime factorisations of all numbers less than it.
So, in base 10, the number of zeroes at the end of a number is given by the number of times 5 occurs in the prime factorisation of all numbers upto n.
This is given by n/5 + n/5^2 + n/5^3 + ... */

//Function Prototype
int determine_power_of_five(long long);

int main()
{
    int no_of_input, no_of_zeroes, i;
    long long num;

    scanf("%d",&no_of_input);

    for(i = 0; i < no_of_input; i++)
    {
        scanf("%lld",&num);
        no_of_zeroes = determine_power_of_five(num);
        printf("%d\n",no_of_zeroes);
    }
    return 0;
}

//Determine the highest power of five smaller than num
int determine_power_of_five(long long num)
{
    int power = 0, x;

    while(num > 0)
    {
        x = num/5;
        power = power + x;
        num = x;
    }

    return power;
}
