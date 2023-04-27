/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** print_num
*/

#include "print.h"

/**
 * It prints the number `arg` to the standard error stream
 *
 * @param arg The argument to print.
 * @param int The type of the argument.
 */
void print_num(unsigned long long arg, UNUSED int pid)
{
    (void)(print_table);
    (void)(table);
    fprintf(stderr, "%lld", arg);
}
