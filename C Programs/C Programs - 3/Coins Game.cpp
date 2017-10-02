#include <cstdio>
#include <vector>

using namespace std;

#define legal_move(n) (n >= 0 ? true : false)

void precompute(vector <int> &winner, int MAX_GAMES, int k, int l)
{
    winner[0] = 2;

    for(int i = 1; i < MAX_GAMES; i++)
    {
        if(winner[i - 1] == 2 || (legal_move(i - k) && winner[i - k] == 2)  || (legal_move(i - l) && winner[i - l] == 2))
        {
            winner[i] = 1;
        }
        else
        {
            winner[i] = 2;
        }
    }
}

int main()
{
    const int MAX_GAMES = 1e6 + 1;
    vector <int> winner(MAX_GAMES);
    int no_of_games, k, l;
    scanf("%d %d %d", &k, &l, &no_of_games);

    precompute(winner, MAX_GAMES, k, l);

    while(no_of_games--)
    {
        int no_of_coins;
        scanf("%d", &no_of_coins);
        printf("%c", winner[no_of_coins] == 1 ? 'A' : 'B');
    }

    return 0;
}
