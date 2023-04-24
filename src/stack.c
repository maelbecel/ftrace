/*
** EPITECH PROJECT, 2023
** ftrace
** File description:
** stack
*/

#include "stack.h"

my_stack_t *stack_init(void)
{
    my_stack_t *stack = malloc(sizeof(my_stack_t));

    if (!stack)
        return (NULL);
    stack->func = NULL;
    stack->next = NULL;
    return (stack);
}

my_stack_t *stack_push(my_stack_t *stack, char *func)
{
    my_stack_t *new = malloc(sizeof(my_stack_t));

    if (!new)
        return (NULL);
    new->func = func;
    new->next = stack;
    return (new);
}

my_stack_t *stack_pop(my_stack_t **stack)
{
    my_stack_t *tmp = *stack;

    if (!tmp)
        return (NULL);
    *stack = (*stack)->next;
    return (tmp);
}

void stack_print(my_stack_t *stack)
{
    my_stack_t *tmp = stack;

    while (tmp->func) {
        printf("%s\n", tmp->func);
        tmp = tmp->next;
    }
}

void steak_frite(my_stack_t *stack)
{
    my_stack_t *tmp = stack;

    while (stack->func) {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

int stack_length(my_stack_t *stack)
{
    my_stack_t *tmp = stack;
    int i = 0;

    while (tmp) {
        i++;
        tmp = tmp->next;
    }
    return (i);
}
