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
    size_t len = 0;
    int i, fd;
    Elf *e;
    size_t n, shstrndx;
    char *name;
    char *p;
    Elf_Data *data;
    Elf_Scn *scn;
    GElf_Shdr shdr;

    if (elf_version(EV_CURRENT) == EV_NONE )
        errx(EX_SOFTWARE , "ELF library initialization failed : %s ", elf_errmsg(-1));
    if ((fd = open(argv[1], O_RDONLY, 0)) < 0)
        err(EX_NOINPUT , "open \"%s\" failed", argv[1]);
    if ((e = elf_begin (fd, ELF_C_READ , NULL )) == NULL )
        errx(EX_SOFTWARE, "elf_begin() failed: %s.", elf_errmsg(-1));
    if (elf_kind(e) != ELF_K_ELF)
        errx(EX_DATAERR, "\"%s\" is not an ELF object.", argv[1]);
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
    for (i = 0; i < n; i++) {
        GElf_Sym sym;
        if (gelf_getsym(data, i, &sym) != &sym)
            errx(EX_SOFTWARE, "getsym() failed: %s." ,elf_errmsg(-1));
        if (GELF_ST_TYPE(sym.st_info) != STT_FUNC)
            continue;
        if ((name = elf_strptr(e, shdr.sh_link, sym.st_name)) == NULL)
            errx(EX_SOFTWARE, "strptr() failed: %s." ,elf_errmsg(-1));
        if (strcmp(name, "main") == 0)
            if (strtoll(argv[2], NULL, 16) == sym.st_value)
                printf("Main exist!\n");
            else
                printf("Main doesn't exist!\n");
    }
    elf_end(e);
    close(fd);

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