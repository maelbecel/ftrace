/*
** EPITECH PROJECT, 2023
** PSU
** File description:
** get_symbol
*/

#include "ftrace.h"

char *get_name(long sym_addr, GElf_Shdr *shdr, Elf_Scn *scn, Elf **e)
{
    size_t n = 0;
    Elf_Data *data = NULL;
    char *name;

    if ((data = elf_getdata(scn, NULL)) == NULL)
        errx(EX_SOFTWARE, "getdata(scn) failed: %s." ,elf_errmsg(-1));
    if (shdr->sh_entsize > 0)
        n = shdr->sh_size / shdr->sh_entsize;
    for (size_t i = 0; i < n; i++) {
        GElf_Sym sym;
        if (gelf_getsym(data, i, &sym) != &sym)
            errx(EX_SOFTWARE, "getsym() failed: %s." ,elf_errmsg(-1));
        if (GELF_ST_TYPE(sym.st_info) != STT_FUNC) continue;
        if ((name = elf_strptr(*e, shdr->sh_link, sym.st_name)) == NULL)
            errx(EX_SOFTWARE, "strptr() failed: %s." ,elf_errmsg(-1));
        if (sym_addr >= (long)sym.st_value &&
        (long unsigned int)sym_addr <= sym.st_value + sym.st_size)
            return name;
    }
    return NULL;
}

Elf_Scn *get_scene(Elf **e, size_t shstrndx, GElf_Shdr *shdr)
{
    Elf_Scn *scn = NULL;
    char *name;

    while ((scn = elf_nextscn(*e, scn)) != NULL) {
        if (gelf_getshdr(scn, shdr) != shdr)
            errx(EX_SOFTWARE, "getshdr() failed: %s.", elf_errmsg(-1));
        if ((name = elf_strptr (*e, shstrndx, shdr->sh_name)) == NULL )
            errx(EX_SOFTWARE, "elf_strptr() failed: %s.", elf_errmsg(-1));
        if (strcmp(name, ".symtab") == 0)
            break;
    }
    if (scn == NULL)
        return NULL;
    return scn;
}

Elf *get_shdrstrndx(int *fd, pid_t pid)
{
    char *filename = calloc(sizeof(char), 14 + strlen(inttochar(pid)));
    Elf *e;

    strcat(filename, "/proc/");
    strcat(filename, inttochar(pid));
    strcat(filename, "/exe");
    if (elf_version(EV_CURRENT) == EV_NONE)
        errx(EX_SOFTWARE , "ELF library initialization failed : %s ",
        elf_errmsg(-1));
    if ((*fd = open(filename, O_RDONLY)) < 0)
        err(EX_NOINPUT , "open \"%s\" failed", filename);
    if ((e = elf_begin(*fd, ELF_C_READ , NULL )) == NULL )
        errx(EX_SOFTWARE, "elf_begin() failed: %s.", elf_errmsg(-1));
    if (elf_kind(e) != ELF_K_ELF)
        errx(EX_DATAERR, "\"%s\" is not an ELF object.", filename);
    free(filename);
    return e;
}

char *get_exe(long sym_addr, pid_t pid)
{
    int fd = 0;
    Elf *e;
    GElf_Shdr shdr;
    size_t shstrndx;
    Elf_Scn *scn = NULL;
    char *name = NULL;

    e = get_shdrstrndx(&fd, pid);
    if (elf_getshdrstrndx(e, &shstrndx) != 0)
        errx(EX_SOFTWARE, "getshdr() failed: %s.", elf_errmsg(-1));
    scn = get_scene(&e, shstrndx, &shdr);
    if (!scn)
        return NULL;
    name = get_name(sym_addr, &shdr, scn, &e);
    close(fd);
    return name;
}
