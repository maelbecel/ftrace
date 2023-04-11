/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** syscalls
*/

#include "fff.h"
#include <criterion/criterion.h>
#include "../include/ftrace.h"
#include "../include/syscalls.h"

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

void call_ftrace(int ac, char *av[])
{
    pid_t new_pid = 0;
    pid_t pid = 0;
    bool detailed = false;

    check_arg(ac, av, &new_pid, &detailed);
    if ((pid = fork()) == 0) {
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execvp((detailed ? av[2] : av[1]), (detailed ? av + 3 : av + 2));
    } else {
        if (new_pid != 0)
            pid = new_pid;
        ftrace(pid, detailed);
    }
}

////////////////////////////////////////////////////////////////////////
///                              ftrace
////////////////////////////////////////////////////////////////////////
void ftrace(pid_t pid, bool detailed);

Test(ftrace, bad_pid)
{
    ftrace((pid_t)1664, true);
    ftrace((pid_t)1664, false);
}

Test(ftrace, basic_test)
{
    ftrace(getpid(), true);
    ftrace(getpid(), false);
}
