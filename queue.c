#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (q == NULL)
        return NULL;

    q->head = NULL;
    q->tail = q->head;
    q->size = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if (q == NULL)
        return;

    list_ele_t *tmp = NULL;

    while (q->head != NULL) {
        free(q->head->value);
        tmp = q->head->next;
        free(q->head);
        q->head = tmp;
    }

    /* Free queue structure */
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (q == NULL)
        return false;

    list_ele_t *newh = malloc(sizeof(list_ele_t));
    if (newh == NULL)
        return false;

    newh->next = q->head;
    if (newh->next == NULL)
        q->tail = newh;

    q->head = newh;
    q->size++;

    size_t length = strlen(s) + sizeof(char);
    newh->value = malloc(length);
    if (newh->value == NULL) {
        free(newh);
        return false;
    }

    memset(newh->value, 0, length);
    strncpy(newh->value, s, length);
    newh->value[length - 1] = '\0';

    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    if (q == NULL)
        return false;

    list_ele_t *newh = malloc(sizeof(list_ele_t));
    if (newh == NULL)
        return false;

    newh->next = NULL;
    if (q->tail == NULL) {
        q->tail = newh;
        q->head = q->tail;
    } else {
        q->tail->next = newh;
        q->tail = newh;
    }

    q->size++;

    size_t length = strlen(s) + sizeof(char);
    newh->value = malloc(length);
    if (newh->value == NULL) {
        free(newh);
        return false;
    }

    memset(newh->value, 0, length);
    strncpy(newh->value, s, length);
    newh->value[length - 1] = '\0';

    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    if (q == NULL || q->head == NULL)
        return false;

    list_ele_t *tmp = q->head;
    q->head = q->head->next;
    if (q->head == NULL)
        q->tail = NULL;

    q->size--;

    if (tmp->value != NULL) {
        if (sp != NULL) {
            size_t length = (strlen(tmp->value) < bufsize - 1)
                                ? strlen(tmp->value)
                                : bufsize - 1;
            strncpy(sp, tmp->value, length);
            sp[length] = '\0';
        }
        free(tmp->value);
    }
    free(tmp);

    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (q == NULL)
        return 0;

    return q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
