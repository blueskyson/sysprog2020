#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
typedef struct __node {
    int value;
    struct __node *next;
} node_t;

void add_entry(node_t **head, int new_value)
{
    node_t **indirect = head;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = new_value;
    new_node->next = NULL;

    assert(new_node);
    while (*indirect)
        indirect = &(*indirect)->next;
    *indirect = new_node;
}

node_t *find_entry(node_t *head, int value)
{
    node_t *current = head;
    for (; current && current->value != value; current = current->next)
        /* interate */;
    return current;
}

void remove_entry(node_t **head, node_t *entry)
{
    node_t **indirect = head;

    while ((*indirect) != entry)
        indirect = &(*indirect)->next;

    *indirect = entry->next;
    free(entry);
}

node_t *swap_pair(node_t *head)
{
    for (node_t **node = &head; *node && (*node)->next;
    node = &(*node)->next->next) {
        node_t *tmp = *node;
        *node = (*node)->next;
        tmp->next = (*node)->next;
        (*node)->next = tmp;
    }
    return head;
}

node_t *reverse(node_t *head)
{
    node_t *cursor = NULL;
    while (head) {
        node_t *next = head->next;
        head->next = cursor;
        cursor = head;
        head = next;
    }
    return cursor;
}

void print_list(node_t *head)
{
    for (node_t *current = head; current; current = current->next)
        printf("%d ", current->value);
    printf("\n");
}

void fisher_yates_shuffle(node_t **head)
{
    if (!head || !(*head) || !(*head)->next)
        return;

    srand(time(NULL));
    int i, max = 1;
    node_t *tail;
    for (tail = *head; tail->next; tail = tail->next)
        max++;
    
    for (i = max; i > 0; --i) {
        int j, picknum = rand() % i;
        if (picknum == 0) {
            tail->next = *head;
            *head = (*head)->next;
            tail = tail->next;
            tail->next = NULL;
            continue;
        }

        node_t *prev;
        for (j = 0, prev = *head; j < picknum - 1; j++)
            prev = prev->next;
        tail->next = prev->next;
        prev->next = prev->next->next;
        tail = tail->next;
        tail->next = NULL;
    }
}

int main() {
    node_t *head = NULL;

    print_list(head);

    add_entry(&head, 72);
    add_entry(&head, 101);
    add_entry(&head, 108);
    add_entry(&head, 109);
    add_entry(&head, 110);
    add_entry(&head, 111);

    printf("Original list:\n");
    print_list(head);
    fisher_yates_shuffle(&head);
    printf("\nShuffled list:\n");
    print_list(head);

    return 0;
}