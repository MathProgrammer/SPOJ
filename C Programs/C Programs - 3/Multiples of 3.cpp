#include <cstdio>

const int MAX_SIZE = 1e5 + 3;

int tree[3*MAX_SIZE][3];
int lazy[3*MAX_SIZE] = {0};
int element[MAX_SIZE] = {0};

void swap(int &a, int &b, int &c)
{
    int temp_a = a, temp_b = b, temp_c = c;

    c = temp_b;
    b = temp_a;
    a = temp_c;
}

void build(int node, int start, int end)
{
    if(start == end)
    {
        int mod = element[start]%3;
        int mod_2 = (mod + 1)%3, mod_3 = (mod + 2)%3;

        tree[node][mod] = 1;
        tree[node][mod_2] = tree[node][mod_3] = 0;

        return;
    }

    int mid = (start + end)/2;

    build(2*node, start, mid);
    build(2*node + 1, mid + 1, end);

    for(int m = 0; m < 3; m++)
        tree[node][m] = tree[2*node][m] + tree[2*node + 1][m];
}

void propagate(int node, int start, int end)
{
    int no_of_additions = lazy[node]%3;

    if(no_of_additions == 1)
    {
        swap(tree[node][0], tree[node][1], tree[node][2]);
    }
    else if(no_of_additions == 2)
    {
        swap(tree[node][0], tree[node][2], tree[node][1]);
    }

    if(start != end)
    {
        lazy[2*node] = (lazy[2*node] + lazy[node])%3;
        lazy[2*node + 1] = (lazy[2*node + 1] + lazy[node])%3;
    }
    lazy[node] = 0;
}

void update(int node, int start, int end, int query_start, int query_end)
{
    if(lazy[node])
        propagate(node, start, end);

    if(query_start > end || query_end < start)
        return;

    if(query_start <= start && end <= query_end)
    {
        swap(tree[node][0], tree[node][1], tree[node][2]);

        if(start != end)
        {
            lazy[2*node]++;
            lazy[2*node] %= 3;

            lazy[2*node + 1]++;
            lazy[2*node + 1] %= 3;
        }
        return;
    }

    int mid = (start + end)/2;

    update(2*node, start, mid, query_start, query_end);
    update(2*node + 1, mid + 1, end, query_start, query_end);

    for(int m = 0; m < 3; m++)
        tree[node][m] = tree[2*node][m] + tree[2*node + 1][m];
}

int query(int node, int start, int end, int query_start, int query_end)
{
    if(lazy[node])
        propagate(node, start, end);

    if(query_start > end || query_end < start)
        return 0;

    if(query_start <= start && end <= query_end)
        return tree[node][0];

    int mid = (start + end)/2;

    int left_answer  = query(2*node, start, mid, query_start, query_end);
    int right_answer = query(2*node + 1, mid + 1, end, query_start, query_end);

    return (left_answer + right_answer);
}

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    build(1, 1, no_of_elements);

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int type, left, right;
        scanf("%d %d %d", &type, &left, &right);

        left++, right++;

        if(type == 0)
        {
            update(1, 1, no_of_elements, left, right);
        }
        else if(type == 1)
        {
            int answer = query(1, 1, no_of_elements, left, right);
            printf("%d\n", answer);
        }
    }

    return 0;
}
