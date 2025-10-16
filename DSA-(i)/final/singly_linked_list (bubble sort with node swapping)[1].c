#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node * next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void print()
{
    struct Node *tmp = head;
    printf("List : ");

    while(tmp != NULL)
    {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }

    printf("\n\n");
}

void insert_at_head(int val)
{
    struct Node *tmp = (struct Node*) malloc(sizeof(struct Node));
    tmp->val = val;
    tmp->next = head;
    head = tmp;
}

void insert_at_tail(int val)
{
    struct Node *tmp = (struct Node*) malloc(sizeof(struct Node));
    tmp->val = val;
    tmp->next = NULL;
    tail->next = tmp;
    tail = tmp; 
}

// bubble sort for singly linked list
void sort()
{
    if(head == NULL || head->next == NULL) return;

    struct Node *prev, *slow, *fast, *end = NULL;

    while(head->next != end)
    {
        int swapped = 0;
        prev = NULL, slow = head, fast = head->next;

        while(fast != end)
        {
            if(slow->val > fast->val)
            {
                slow->next = fast->next;
                if(slow->next == NULL) tail = slow; // handling tail while sorting
                fast->next = slow;

                if(prev == NULL) head = fast; // handling head while sorting
                else prev->next = fast;

                // swap slow and fast for next iteration
                struct Node *tmp = slow;
                slow = fast;
                fast = tmp;

                swapped = 1;
            }

            prev = slow; // move prev

            slow = slow->next;
            fast = fast->next;
        }

        if(!swapped) break;

        end = slow;
    }
}

int main()
{
    while(1)
    {
        printf("1. Insert at head\n2. Insert at tail\n3. Sort the list\n4. Print list\n\n");
        printf("Enter your choice : ");

        int ch;
        scanf("%d", &ch);
        
        if(ch == -1) break;
        else if(ch == 1)
        {
            printf("Enter a value : ");
            int val;
            scanf("%d", &val);

            if(head == NULL)
            {
                head = (struct Node*) malloc(sizeof(struct Node));
                head->val = val;
                head->next = NULL;
                tail = head;
            }
            else insert_at_head(val);
        }
        else if(ch == 2)
        {
            printf("Enter a value : ");
            int val;
            scanf("%d", &val);

            if(tail == NULL)
            {
                head = (struct Node*) malloc(sizeof(struct Node));
                head->val = val;
                head->next = NULL;
                tail = head;
            }
            else insert_at_tail(val);
        }
        else if(ch == 3)
        {
            if(head == NULL) continue;
            else if(head->next == NULL) continue;
            else sort();
        }
        else if(ch == 4) print();
    }

    return 0;
}