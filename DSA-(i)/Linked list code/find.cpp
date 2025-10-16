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

    if (find(head, x))
    {
        printf("\nfind this");
    }
    else
    {
        printf("\nnot find");
    }

}
