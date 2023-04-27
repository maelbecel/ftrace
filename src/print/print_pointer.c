/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** print_num
*/

#include "print.h"

/**
 * If the argument is non-zero, print it as a hexadecimal number, otherwise
 * print the word "NULL"
 *
 * @param arg The argument to print.
 * @param int The type of the argument.
 */
void print_pointer(unsigned long long arg, UNUSED int pid)
{
    (void)(print_table);
    (void)(table);
    if (arg)
        fprintf(stderr, "%#llx", arg);
    else
        fprintf(stderr, "NULL");
}
