/*
** EPITECH PROJECT, 2023
** ftrace
** File description:
** stack
*/

#include "stack.h"

stack_t *stack_init(void)
{
    stack_t *stack = malloc(sizeof(stack_t));

    if (!stack)
        return (NULL);
    stack->func = NULL;
    stack->next = NULL;
    return (stack);
}

stack_t *stack_push(stack_t *stack, char *func)
{
    stack_t *new = malloc(sizeof(stack_t));

    if (!new)
        return (NULL);
    new->func = func;
    new->next = stack;
    return (new);
}

stack_t *stack_pop(stack_t *stack)
{
    if (!stack)
        return (NULL);
    return (stack->next);
}

void stack_print(stack_t *stack)
{
    stack_t *tmp = stack;

    while (tmp->func) {
        printf("%s\n", tmp->func);
        tmp = tmp->next;
    }
}

void steak_frite(stack_t *stack)
{
    stack_t *tmp = stack;

    while (stack->func) {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

int stack_length(stack_t *stack)
{
    stack_t *tmp = stack;
    int i = 0;

    while (tmp) {
        i++;
        tmp = tmp->next;
    }
    return (i);
}
