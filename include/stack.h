/*
** EPITECH PROJECT, 2023
** ftrace
** File description:
** stack
*/

#ifndef STACK_H_
    #define STACK_H_

    #include <stdlib.h>
    #include <stddef.h>

    typedef struct stack_s {
        char *func;
        struct stack_s *next;
    } my_stack_t;

    my_stack_t *stack_push(my_stack_t *stack, char *func);
    my_stack_t *stack_pop(my_stack_t **stack);
    void stack_print(my_stack_t *stack);
    void steak_frite(my_stack_t *stack);
    my_stack_t *stack_init(void);
    int stack_length(my_stack_t *stack);


#endif /* !STACK_H_ */
