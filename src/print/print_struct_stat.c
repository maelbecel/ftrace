/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** print_struct_stat
*/

#include <ftrace.h>
#include <sys/sysmacros.h>

/**
 * It takes a struct stat as an argument and returns an integer representing
 * the permissions of the file
 *
 * @param infos The struct stat that contains the file's information.
 *
 * @return The permissions of the file.
 */
int get_perms(struct stat infos)
{
    int perms = 0000;
    mode_t bits = infos.st_mode;

    perms += (bits & S_IXUSR ? 100 : 0);
    perms += (bits & S_IWUSR ? 200 : 0);
    perms += (bits & S_IRUSR ? 400 : 0);
    perms += (bits & S_IXGRP ? 10 : 0);
    perms += (bits & S_IWGRP ? 20 : 0);
    perms += (bits & S_IRGRP ? 40 : 0);
    perms += (bits & S_IXOTH ? 1 : 0);
    perms += (bits & S_IWOTH ? 2 : 0);
    perms += (bits & S_IROTH ? 4 : 0);
    return perms;
}

/**
 * It checks the mode of the file and returns a string that describes the mode
 *
 * @param infos the struct stat that contains the information about the file
 *
 * @return The type of file.
 */
char *check_mode(struct stat infos)
{
    if (S_ISDIR(infos.st_mode))
        return "S_IFDIR";
    if (S_ISREG(infos.st_mode))
        return "S_IFREG";
    if (S_ISCHR(infos.st_mode))
        return "S_IFCHR";
    if (S_ISBLK(infos.st_mode))
        return "S_IFBLK";
    if (S_ISFIFO(infos.st_mode))
        return "S_IFFIFO";
    if (S_ISLNK(infos.st_mode))
        return "S_IFLNK";
    return "";
}

/**
 * It reads the memory of the child process and copies it into the struct stat
 *
 * @param pid the pid of the process we want to trace
 * @param args the address of the struct stat in the child process
 * @param infos the struct stat we want to fill
 */
void get_struct(pid_t pid, unsigned long long args, struct stat *infos)
{
    char s = -1;

    for (int i = 0; (unsigned long)i < sizeof(struct stat) - 1; i++) {
        s = ptrace(PTRACE_PEEKDATA, pid, args + i, NULL);
        memcpy((char *)infos + i, &s, 1);
    }
}

/**
 * It prints the content of a struct stat
 *
 * @param args the address of the struct stat in the child process
 * @param pid the pid of the process we want to get the syscall from
 */
void print_struct_stat(unsigned long long args, pid_t pid)
{
    struct stat infos;

    get_struct(pid, args, &infos);
    fprintf(stderr, "{st_mode=%s|%04d, ", check_mode(infos), get_perms(infos));
    if (S_ISCHR(infos.st_mode) || S_ISBLK(infos.st_mode))
        fprintf(stderr, "st_rdev=makedev(%#x, %#x), ...}", major(infos.st_rdev),
        minor(infos.st_rdev));
    else
        fprintf(stderr, "st_size=%ld, ...}", infos.st_size);
}
