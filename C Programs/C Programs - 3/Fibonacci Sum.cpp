#include <cstdio>

const int N = 2, MOD = 1e9 + 7;

void load_identity(long long I[N][N])
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            I[i][j] = (i == j ? 1 : 0);
}

void copy(long long A[N][N], long long B[N][N])
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            B[i][j] = A[i][j];
}

void multiply(long long A[N][N], long long B[N][N])
{
    long long P[N][N];

    for(int row = 0; row < N; row++)
    {
        for(int column = 0; column < N; column++)
        {
            P[row][column] = 0;

            for(int i = 0; i < N; i++)
                P[row][column] += (A[row][i]*B[i][column])%MOD;

            P[row][column] %= MOD;
        }
    }

    copy(P, A);
}

void power(long long X[N][N], long long power)
{
    long long result[N][N];
    load_identity(result);

    while(power)
    {
        if(power%2 == 1)
            multiply(result, X);

        multiply(X, X);
        power = power >> 1;
    }

    copy(result, X);
}

long long fibo(long long n)
{
    long long fibonacci[N][N] = { {1, 0} };
    long long matrix[N][N] = { {1, 1},
                               {1, 0} };


    if(n <= 1)
        return n;

    power(matrix, n - 1);
    multiply(fibonacci, matrix);

    return fibonacci[0][0];
}

void solve()
{
    long long n, m;
    scanf("%lld %lld", &n, &m);

    long long n_sum = fibo(n + 1) + MOD - 1;
    long long m_sum = fibo(m + 2) + MOD - 1;

    long long total = (m_sum + MOD - n_sum)%MOD;
    printf("%lld\n", total);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
