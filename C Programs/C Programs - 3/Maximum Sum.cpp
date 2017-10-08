#include <cstdio>

#define max(a, b) (a > b ? a : b)
#define max_3(a, b, c) max(a, max(b, c))

const int MAX_SIZE = 1e5 + 3;

int max_sum_tree[3*MAX_SIZE];
int max_tree[3*MAX_SIZE];
int element[MAX_SIZE];

void build(int node, int start, int end)
{
    if(start == end)
    {
        max_tree[node] = max_sum_tree[node] = element[start];
        return;
    }

    int mid = (start + end)/2;

    build(2*node, start, mid);
    build(2*node + 1, mid + 1, end);

    max_tree[node] = max(max_tree[2*node], max_tree[2*node + 1]);
    max_sum_tree[node] = max_3(max_sum_tree[2*node], max_sum_tree[2*node + 1], max_tree[2*node] + max_tree[2*node + 1]);
}

void update(int node, int start, int end, int index, int value)
{
    if(start == end)
    {
        max_sum_tree[node] = max_tree[node] = element[index] = value;
        return;
    }

    int mid = (start + end)/2;

    if(start <= index && index <= mid)
    {
        update(2*node, start, mid, index, value);
    }
    else if(mid <= index && index <= end)
    {
        update(2*node + 1, mid + 1, end, index, value);
    }

    max_tree[node] = max(max_tree[2*node], max_tree[2*node + 1]);
    max_sum_tree[node] = max_3(max_sum_tree[2*node], max_sum_tree[2*node + 1], max_tree[2*node] + max_tree[2*node + 1]);
}

int query_max(int node, int start, int end, int query_start, int query_end)
{
    if(query_start > end || query_end < start)
        return 0;

    if(query_start <= start && end <= query_end)
    {
        return max_tree[node];
    }

    int mid = (start + end)/2;

    int left_max  = query_max(2*node, start, mid, query_start, query_end);
    int right_max = query_max(2*node + 1, mid + 1, end, query_start, query_end);

    return max(left_max, right_max);
}

int query(int node, int start, int end, int query_start, int query_end)
{
    if(query_start > end || query_end < start)
        return 0;

    if(query_start <= start && end <= query_end)
        return max_sum_tree[node];

    int mid = (start + end)/2;

    int left_max = query_max(2*node, start, mid, query_start, query_end);
    int right_max = query_max(2*node + 1, mid + 1, end, query_start, query_end);

    int left_answer =  query(2*node, start, mid, query_start, query_end);
    int right_answer = query(2*node + 1, mid + 1, end, query_start, query_end);

    return max_3(left_answer, right_answer, left_max + right_max);
}

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &element[i]);

    build(1, 1, no_of_elements);

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        char type;
        int left, right;

        scanf(" %c %d %d", &type, &left, &right);

        if(type == 'Q')
        {
            int answer = query(1, 1, no_of_elements, left, right);
            printf("%d\n", answer);
        }
        else if(type == 'U')
        {
            update(1, 1, no_of_elements, left, right);
        }
    }

    return 0;
}
