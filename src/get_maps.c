/*
** EPITECH PROJECT, 2023
** B-PSU-400
** File description:
** get_maps
*/

#include "ftrace.h"

char *get_exe(long long rip, pid_t pid)
{
    char *filename = calloc(sizeof(char), 14 + strlen(inttochar(pid)));
    char *name;
    int fd;
    Elf *e;
    size_t n, shstrndx;
    Elf_Data *data;
    Elf_Scn *scn;
    GElf_Shdr shdr;

    strcat(filename, "/proc/");
    strcat(filename, inttochar(pid));
    strcat(filename, "/exe");
    if (elf_version(EV_CURRENT) == EV_NONE )
        errx(EX_SOFTWARE , "ELF library initialization failed : %s ", elf_errmsg(-1));
    if ((fd = open(filename, O_RDONLY)) < 0)
        err(EX_NOINPUT , "open \"%s\" failed", filename);
    if ((e = elf_begin(fd, ELF_C_READ , NULL )) == NULL )
        errx(EX_SOFTWARE, "elf_begin() failed: %s.", elf_errmsg(-1));
    if (elf_kind(e) != ELF_K_ELF)
        errx(EX_DATAERR, "\"%s\" is not an ELF object.", filename);
    if (elf_getshdrstrndx(e, &shstrndx) != 0)
        errx(EX_SOFTWARE, "getshdr() failed : %s.", elf_errmsg(-1));
    scn = NULL;
    while ((scn = elf_nextscn(e, scn)) != NULL) {
        if (gelf_getshdr(scn, &shdr) != &shdr)
            errx(EX_SOFTWARE, "getshdr() failed: %s.", elf_errmsg(-1));
        if ((name = elf_strptr (e, shstrndx, shdr.sh_name )) == NULL )
            errx(EX_SOFTWARE, "elf_strptr() failed: %s.", elf_errmsg(-1));
        if (strcmp(name, ".symtab") == 0)
            break;
    }
    data = NULL;
    if (scn == NULL)
        errx(EX_SOFTWARE, "scn failed: %s.", elf_errmsg(-1));
    if ((data = elf_getdata(scn, NULL)) == NULL)
        errx(EX_SOFTWARE, "getdata(scn) failed: %s." ,elf_errmsg(-1));
    n = shdr.sh_size / shdr.sh_entsize;
    for (size_t i = 0; i < n; i++) {
        GElf_Sym sym;
        if (gelf_getsym(data, i, &sym) != &sym)
            errx(EX_SOFTWARE, "getsym() failed: %s." ,elf_errmsg(-1));
        if (GELF_ST_TYPE(sym.st_info) != STT_FUNC)
            continue;
        if ((name = elf_strptr(e, shdr.sh_link, sym.st_name)) == NULL)
            errx(EX_SOFTWARE, "strptr() failed: %s." ,elf_errmsg(-1));
        if (rip >= (long long)sym.st_value && (long unsigned int)rip <= sym.st_value + sym.st_size)
            return name;
    }
    elf_end(e);
    close(fd);
    return NULL;
}

char *get_maps(long long rip, pid_t pid)
{
    char *bin;
    char *name;
    char *filename = calloc(sizeof(char), 14 + strlen(inttochar(pid)));
    int fd = 0;
    char line[30000] = {0};
    char **tmp;
    char **tab;

    strcat(filename, "/proc/");
    strcat(filename, inttochar(pid));
    strcat(filename, "/maps");
    if ((fd = open(filename, O_RDONLY)) == -1)
        return NULL;
    if (read(fd, line, 29999) == -1)
        return NULL;
    tab = my_str_to_word_array(line, '\n');
    for (int i = 0; tab[i]; i++) {
        tmp = tab;
        tmp = my_str_to_word_array(tmp[i], ' ');
        bin = tmp[5];
        tmp = my_str_to_word_array(tmp[0], '-');
        if (strtoll(tmp[0], NULL, 16) <= rip && rip <= strtoll(tmp[1], NULL, 16)) {
            name = get_exe(rip, pid);
            break;
        }
    }
    close(fd);
    if (!name)
        asprintf(&name, "func_%#llx@%s", rip, bin);
    printf("%s\n", name);
    return name;
}
