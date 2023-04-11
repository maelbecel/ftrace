/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** get_syscall
*/

#include "syscalls.h"
#include "ftrace.h"

/**
 * It loops through the syscall table until it finds the syscall with the
 * number that matches the number passed in
 *
 * @param num The syscall number.
 *
 * @return A pointer to a syscall_t struct.
 */
syscall_t get_syscall(int num)
{
    int i = 0;
    for (; table[i].name != NULL; i++) {
        if (table[i].num == num)
            break;
    }
    return table[i];
}
