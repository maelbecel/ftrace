/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "ftrace.h"

/**
 * It checks the arguments
 * passed to the program and returns a value depending on the result
 *
 * @param ac the number of arguments
 * @param av The arguments passed to the program.
 * @param pid the pid of the process to monitor
 * @param detailed if true, the program will print the detailed information of
 * the arguments passed to the system call
 *
 * @return the number of arguments passed to the program.
 */
static int check_arg(int ac, char **av, pid_t *pid, bool *detailed)
{
    if (ac < 2 || (ac > 1 && strcmp(av[1], "--help") == 0)) {
        printf(HELP);
        return 0;
    }
    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "-p") == 0 && av[i + 1] != NULL &&
        my_str_isnum(av[i + 1])) {
            (*pid) = atoi(av[i + 1]);
            i++;
        }
        if (strcmp(av[i], "-s") == 0)
            (*detailed) = true;
    }
    if ((*pid) != 0 || (*detailed) == true)
        return 1;
    return 2;
}

int main(int ac, char **av)
{
    pid_t new_pid = 0;
    pid_t pid = 0;
    bool detailed = false;

    if (check_arg(ac, av, &new_pid, &detailed) == 0)
        return 0;
    if ((pid = fork()) == 0) {
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execvp((detailed ? av[2] : av[1]), (detailed ? av + 3 : av + 2));
    } else {
        if (pid == -1)
            return 84;
        if (new_pid != 0) {
            pid = new_pid;
            ptrace(PTRACE_ATTACH, pid, NULL, NULL);
        }
        ftrace(pid, detailed);
    }
    return 0;
}
