#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int key;
    Node *next;
};
void insert_head(struct Node *&head, struct Node *&tail, int val)
{
    struct Node *temp = (Node *)malloc(sizeof(Node));
    temp->key = val;
    temp->next = head;
    head = temp;
    tail = temp;
}
void insert_tail(struct Node *&head, struct Node *&tail, int val)
{
    struct Node *temp = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        insert_head(head, tail, val);
        return;
    }
    temp->key = val;
    tail->next = temp;
    temp->next = NULL;
    tail = temp;
}

void print(struct Node *&head)
{
    struct Node *temp = (Node *)malloc(sizeof(Node));
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->key);
        temp = temp->next;
    }
}
void delete_head(struct Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}
void delete_tail(struct Node *&head, struct Node *&tail)
{
    if (tail == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        delete_head(head);
    }
    Node *slow = NULL;
    Node *fast = head;
    while (fast != tail)
    {
        slow = fast;
        fast = fast->next;
    }
    tail = slow;
    if (tail != NULL)
        tail->next = NULL;
    if (tail == NULL)
        head = NULL;
    free(fast);
}
bool find(struct Node *&head, int x)
{
    struct Node *temp = (Node *)malloc(sizeof(Node));
    temp = head;
    while (temp != NULL)
    {
        if (temp->key == x)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
bool delete_any(struct Node *&head, struct Node *&tail, int x)
{
    if (find(head, x) == NULL)
    {
        return false;
    }
    if (head->key == x)
    {
        delete_head(head);
        return true;
    }
    if (tail->key == x)
    {
        delete_tail(head, tail);
        return true;
    }
    Node *slow = NULL;
    Node *fast = head;
    while (fast->key != x)
    {
        slow = fast;
        fast = fast->next;
    }
    slow->next = fast->next;
    free(fast);
}
bool delete_last_occ(struct Node *&head, struct Node *&tail, int x)
{
    if (find(head, x) == NULL)
    {
        return false;
    }
    if (head->key == x && head->next->key != x)
    {
        delete_head(head);
        return true;
    }
    if (tail->key == x)
    {
        delete_tail(head, tail);
        return true;
    }
    Node *slow = NULL;
    Node *fast = head;
    while (fast->key != x)
    {

        slow = fast;
        fast = fast->next;
        if (fast->key == x && fast->next->key != x)
            break;
    }
    slow->next = fast->next;
    free(fast);
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        scanf("%d", &val);
        if (val == -1)
        {
            break;
        }
        insert_tail(head, tail, val);
    }
    print(head);
    int x;
    scanf("%d", &x);
    // delete_any(head, tail, x);
    delete_last_occ(head, tail, x);
    printf("\n");
    print(head);
}
