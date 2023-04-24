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
    } stack_t;

    stack_t *stack_push(stack_t *stack, char *func);
    stack_t *stack_pop(stack_t *stack);
    void stack_print(stack_t *stack);
    void steak_frite(stack_t *stack);
    stack_t *stack_init(void);
    int stack_length(stack_t *stack);


#endif /* !STACK_H_ */
