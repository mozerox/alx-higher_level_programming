#include "lists.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

/* Function to check if a linked list is a palindrome */
int is_palindrome(listint_t **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return 1;  // Empty list or single element is considered a palindrome
    }

    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;

        // Reverse the first half of the linked list
        listint_t *temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    // Adjust pointers for odd-sized lists
    if (fast != NULL) {
        slow = slow->next;
    }

    // Compare the reversed first half with the second half
    while (prev != NULL && slow != NULL) {
        if (prev->n != slow->n) {
            return 0;  // Not a palindrome
        }
        prev = prev->next;
        slow = slow->next;
    }

    return 1;  // It is a palindrome
}


void print_list(listint_t *head) {
    while (head != NULL) {
        printf("%d -> ", head->n);
        head = head->next;
    }
    printf("NULL\n");
}

void  push(listint_t **head, int value) {
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL) {
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->next = *head;
    *head = new_node;
}


void free_list(listint_t *head) {
    listint_t *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main() {
    listint_t *head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Original linked list:\n");
    print_list(head);

    if (is_palindrome(&head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    // Free the memory
    free_list(head);

    return 0;
}
