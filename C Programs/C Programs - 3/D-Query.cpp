#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define LEFT(n) (n << 1)
#define RIGHT(n) ( (n << 1)|1 )

const int INSERTION = 0, QUERY = 1, MAX_N = 1e6 + 5, OLD_LAST_OCCURENCE = 0, NEW_LAST_OCCURENCE = 1;
int tree[3*MAX_N];

struct info
{
    int end;
    int type;
    int position, value;
    int left, right, query_no;

    info(){ end = type = left = right = query_no = position = -1; }
};

int compare_ends(const info &A, const info &B)
{
    if(A.end < B.end)
        return true;
    else if(A.end == B.end)
        return (A.type == INSERTION);

    return false;
}

void insert(int n, int left, int right, int position, int position_type)
{
    if(right < position || position < left)
        return;

    if(left == right)
    {
        if(position_type == OLD_LAST_OCCURENCE)
            tree[n] = 0;
        else if(position_type == NEW_LAST_OCCURENCE)
            tree[n] = 1;

        return;
    }

    int mid = (left + right) >> 1;

    if(position <= mid)
        insert(LEFT(n), left, mid, position, position_type);
    else if(position > mid)
        insert(RIGHT(n), mid + 1, right, position, position_type);

    tree[n] = tree[LEFT(n)] + tree[RIGHT(n)];
}

int query(int n, int left, int right, int query_left, int query_right)
{
   if(query_right < left || right < query_left)
       return 0;

    if(query_left <= left && right <= query_right)
        return tree[n];

    int mid = (left + right) >> 1;

    int left_answer = query(LEFT(n), left, mid, query_left, query_right);
    int right_answer = query(RIGHT(n), mid + 1, right, query_left, query_right);

    return (left_answer + right_answer);
}

int main()
{
    memset(tree, 0, sizeof(tree));

    vector <info> event;

    int no_of_elements;
    scanf("%d", &no_of_elements);
    for(int i = 1; i <= no_of_elements; i++)
    {
        info current_event;
        current_event.type = INSERTION;
        current_event.end = current_event.position = i;
        scanf("%d", &current_event.value);

        event.push_back(current_event);
    }

    int no_of_queries;
    scanf("%d", &no_of_queries);
    for(int i = 1; i <= no_of_queries; i++)
    {
        info current_event;
        current_event.type = QUERY;

        scanf("%d %d", &current_event.left, &current_event.right);
        current_event.end = current_event.right;
        current_event.query_no = i;

        event.push_back(current_event);
    }

    sort(all(event), compare_ends);

    int no_of_events = no_of_elements + no_of_queries;

    map <int, int> last_occurence;
    vector <int> answer(no_of_queries + 1);

    for(int i = 0; i < no_of_events; i++)
    {
       if(event[i].type == INSERTION)
       {
           int element = event[i].value;

           if(last_occurence.count(element) == 1)
           {
               insert(1, 1, no_of_elements, last_occurence[element], OLD_LAST_OCCURENCE);
           }

           insert(1, 1, no_of_elements, event[i].position, NEW_LAST_OCCURENCE);
           last_occurence[element] = event[i].position;
       }
       else if(event[i].type == QUERY)
       {
           answer[event[i].query_no] = query(1, 1, no_of_elements, event[i].left, event[i].right);
       }
    }

    for(int i = 1; i <= no_of_queries; i++)
        printf("%d\n", answer[i]);

    return 0;
}
