/*
** EPITECH PROJECT, 2023
** B-PSU-400
** File description:
** get_maps
*/

#include "ftrace.h"

char *parse_maps(char *line, long sym_addr, pid_t pid)
{
    char **tab = my_str_to_word_array(line, '\n');
    char **tmp;
    char *lib;
    char *name;
    char *offset;

    for (int i = 0; tab[i]; i++) {
        tmp = tab;
        tmp = my_str_to_word_array(tmp[i], ' ');
        offset = tmp[3];
        lib = tmp[5];
        tmp = my_str_to_word_array(tmp[0], '-');
        if (strtoll(tmp[0], NULL, 16) <= sym_addr && sym_addr <= strtoll(tmp[1], NULL, 16)) {
            name = get_exe(sym_addr + strtoll(offset, NULL, 16), pid);
            break;
        }
    }
    if (!name)
        asprintf(&name, "func_%#lX@%s", sym_addr, lib);
    return name;
}

char *get_maps(long sym_addr, pid_t pid)
{
    char *filename = calloc(sizeof(char), 14 + strlen(inttochar(pid)));
    char line[30000] = {0};
    char *name;
    int fd = 0;

    strcat(filename, "/proc/");
    strcat(filename, inttochar(pid));
    strcat(filename, "/maps");
    if ((fd = open(filename, O_RDONLY)) == -1)
        return NULL;
    if (read(fd, line, 29999) == -1)
        return NULL;
    name = parse_maps(line, sym_addr, pid);
    free(filename);
    close(fd);
    return name;
}
