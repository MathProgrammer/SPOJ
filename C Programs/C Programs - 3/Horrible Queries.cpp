#include <cstdio>
#include <cstring>

typedef long long LL;
const int MAX_SIZE = 1e5 + 3;

LL tree[3*MAX_SIZE] = {0};
LL lazy[3*MAX_SIZE] = {0};
LL element[MAX_SIZE] = {0};

void propagate(int node, int start, int end)
{
    LL no_of_elements = end - (start - 1);
    tree[node] += lazy[node]*no_of_elements;

    if(start != end)
    {
        lazy[2*node] += lazy[node];
        lazy[2*node + 1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(int node, int start, int end, int query_start, int query_end, int value)
{
    if(lazy[node])
        propagate(node, start, end);

    if(query_start > end || query_end < start)
        return;

    if(query_start <= start && end <= query_end)
    {
        LL no_of_elements = end - (start - 1);
        tree[node] += no_of_elements*value;

        if(start != end)
        {
            lazy[2*node] += value;
            lazy[2*node + 1] += value;
        }

        return;
    }

    int mid = (start + end)/2;

    update(2*node, start, mid, query_start, query_end, value);
    update(2*node + 1, mid + 1, end, query_start, query_end, value);

    tree[node] = tree[2*node] + tree[2*node + 1];
}

LL query(int node, int start, int end, int query_start, int query_end)
{
    if(lazy[node])
        propagate(node, start, end);

    if(query_start > end || query_end < start)
        return 0;

    if(query_start <= start && end <= query_end)
        return tree[node];

    int mid = (start + end) >> 1;

    LL left_answer = query(2*node, start, mid, query_start, query_end);
    LL right_answer = query(2*node + 1, mid + 1, end, query_start, query_end);

    return (left_answer + right_answer);
}

void solve()
{
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));

    int no_of_elements, no_of_queries;
    scanf("%d %d", &no_of_elements, &no_of_queries);

    while(no_of_queries--)
    {
        int type, left, right;
        scanf("%d %d %d", &type, &left, &right);

        if(type == 0)
        {
            int value;
            scanf("%d", &value);
            update(1, 1, no_of_elements, left, right, value);
        }
        else if(type == 1)
        {
            LL answer = query(1, 1, no_of_elements, left, right);
            printf("%lld\n", answer);
        }
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
