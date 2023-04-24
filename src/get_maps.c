/*
** EPITECH PROJECT, 2023
** B-PSU-400
** File description:
** get_maps
*/

#include "ftrace.h"

long long htoll(char *hexastr)
{
    long long ret = 0;
    int i = 0;

    for (i = 0; hexastr[i]; i++) {
        if (hexastr[i] >= '0' && hexastr[i] <= '9')
            ret = ret * 16 + hexastr[i] - '0';
        else if (hexastr[i] >= 'a' && hexastr[i] <= 'f')
            ret = ret * 16 + hexastr[i] - 'a' + 10;
        else if (hexastr[i] >= 'A' && hexastr[i] <= 'F')
            ret = ret * 16 + hexastr[i] - 'A' + 10;
    }
    return ret;
}

void get_maps(long long rip, pid_t pid)
{
    char *filename = calloc(sizeof(char), 14 + strlen(inttochar(pid)));
    int fd = 0;
    char line[30000] = {0};
    char *bin = NULL;
    char **tmp;
    char **tab;

    strcat(filename, "/proc/");
    strcat(filename, inttochar(pid));
    strcat(filename, "/maps");
    if ((fd = open(filename, O_RDONLY)) == -1)
        return;
    if (read(fd, line, 29999) == -1)
        return;
    tab = my_str_to_word_array(line, '\n');
    for (int i = 0; tab[i]; i++) {
        tmp = tab;
        tmp = my_str_to_word_array(tmp[i], ' ');
        bin = tmp[5];
        tmp = my_str_to_word_array(tmp[0], '-');
        if (htoll(tmp[0]) <= rip && rip <= htoll(tmp[1]))
            printf("rip is in %s\n", bin);
    }
    close(fd);
}