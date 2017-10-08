#include <cstdio>

const int MAX_SIZE = 1e5, OFF = 0, ON = 1;
int tree[3*MAX_SIZE];
int lazy[3*MAX_SIZE] = {0};
int light[MAX_SIZE] = {OFF};

void build(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = light[start];
        return;
    }

    int mid = (start + end)/2;
    build(2*node, start, mid);
    build(2*node + 1, mid + 1, end);

    tree[node] = tree[2*node] + tree[2*node + 1];
}

void propagate(int node, int start, int end)
{
    int on_lights = tree[node];
    int total_lights = end - (start - 1);
    int off_lights = total_lights - on_lights;

    if(lazy[node]%2 == 1)
        tree[node] = off_lights;

    if(start != end)
    {
        lazy[2*node] += lazy[node];
        lazy[2*node + 1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(int node, int start, int end, int query_start, int query_end)
{
    if(lazy[node] != 0)
        propagate(node, start, end);

    if(query_start > end || query_end < start)
        return;

    if(query_start <= start && end <= query_end)
    {
        int no_of_lights = end - (start - 1);
        int no_of_on_lights = tree[node];
        int no_of_off_lights = no_of_lights - no_of_on_lights;

        tree[node] = no_of_off_lights;

        if(start != end)
        {
            lazy[2*node]++;
            lazy[2*node + 1]++;
        }
        return;
    }

    int mid = (start + end)/2;

    update(2*node, start, mid, query_start, query_end);
    update(2*node + 1, mid + 1, end, query_start, query_end);

    tree[node] = tree[2*node] + tree[2*node + 1];
}

int query(int node, int start, int end, int query_start, int query_end)
{
    if(lazy[node] != 0)
        propagate(node, start, end);

    if(query_start > end || query_end < start)
        return 0;

    if(query_start <= start && end <= query_end)
        return tree[node];

    int mid = (start + end)/2;

    int left_answer  = query(2*node, start, mid, query_start, query_end);
    int right_answer = query(2*node + 1, mid + 1, end, query_start, query_end);

    return (left_answer + right_answer);
}

int main()
{
    int no_of_lights, no_of_operations;
    scanf("%d %d", &no_of_lights, &no_of_operations);

    build(1, 1, no_of_lights);

    while(no_of_operations--)
    {
        int type, left, right;
        scanf("%d %d %d", &type, &left, &right);

        if(type == 0)
        {
            update(1, 1, no_of_lights, left, right);
        }
        else if(type == 1)
        {
            int answer = query(1, 1, no_of_lights, left, right);
            printf("%d\n", answer);
        }
    }
    return 0;
}
