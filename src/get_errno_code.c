/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** get_errno_code
*/

#include <ftrace.h>
#include <errno.h>

/* An array of 133 elements of type `err_t` which is a structure
containing two fields: `code` and `name`. */
static err_t errno_tab[133] = {
    {EPERM, "EPERM"},
    {ENOENT, "ENOENT"},
    {ESRCH, "ESRCH"},
    {EINTR, "EINTR"},
    {EIO, "EIO"},
    {ENXIO, "ENXIO"},
    {E2BIG, "E2BIG"},
    {ENOEXEC, "ENOEXEC"},
    {EBADF, "EBADF"},
    {ECHILD, "ECHILD"},
    {EAGAIN, "EAGAIN"},
    {ENOMEM, "ENOMEM"},
    {EACCES, "EACCES"},
    {EFAULT, "EFAULT"},
    {ENOTBLK, "ENOTBLK"},
    {EBUSY, "EBUSY"},
    {EEXIST, "EEXIST"},
    {EXDEV, "EXDEV"},
    {ENODEV, "ENODEV"},
    {ENOTDIR, "ENOTDIR"},
    {EISDIR, "EISDIR"},
    {EINVAL, "EINVAL"},
    {ENFILE, "ENFILE"},
    {EMFILE, "EMFILE"},
    {ENOTTY, "ENOTTY"},
    {ETXTBSY, "ETXTBSY"},
    {EFBIG, "EFBIG"},
    {ENOSPC, "ENOSPC"},
    {ESPIPE, "ESPIPE"},
    {EROFS, "EROFS"},
    {EMLINK, "EMLINK"},
    {EPIPE, "EPIPE"},
    {EDOM, "EDOM"},
    {ERANGE, "ERANGE"},
    {EDEADLK, "EDEADLK"},
    {ENAMETOOLONG, "ENAMETOOLONG"},
    {ENOLCK, "ENOLCK"},
    {ENOSYS, "ENOSYS"},
    {ENOTEMPTY, "ENOTEMPTY"},
    {ELOOP, "ELOOP"},
    {EWOULDBLOCK, "EWOULDBLOCK"},
    {ENOMSG, "ENOMSG"},
    {EIDRM, "EIDRM"},
    {ECHRNG, "ECHRNG"},
    {EL2NSYNC, "EL2NSYNC"},
    {EL3HLT, "EL3HLT"},
    {EL3RST, "EL3RST"},
    {ELNRNG, "ELNRNG"},
    {EUNATCH, "EUNATCH"},
    {ENOCSI, "ENOCSI"},
    {EL2HLT, "EL2HLT"},
    {EBADE, "EBADE"},
    {EBADR, "EBADR"},
    {EXFULL, "EXFULL"},
    {ENOANO, "ENOANO"},
    {EBADRQC, "EBADRQC"},
    {EBADSLT, "EBADSLT"},
    {EDEADLOCK, "EDEADLOCK"},
    {EBFONT, "EBFONT"},
    {ENOSTR, "ENOSTR"},
    {ENODATA, "ENODATA"},
    {ETIME, "ETIME"},
    {ENOSR, "ENOSR"},
    {ENONET, "ENONET"},
    {ENOPKG, "ENOPKG"},
    {EREMOTE, "EREMOTE"},
    {ENOLINK, "ENOLINK"},
    {EADV, "EADV"},
    {ESRMNT, "ESRMNT"},
    {ECOMM, "ECOMM"},
    {EPROTO, "EPROTO"},
    {EMULTIHOP, "EMULTIHOP"},
    {EDOTDOT, "EDOTDOT"},
    {EBADMSG, "EBADMSG"},
    {EOVERFLOW, "EOVERFLOW"},
    {ENOTUNIQ, "ENOTUNIQ"},
    {EBADFD, "EBADFD"},
    {EREMCHG, "EREMCHG"},
    {ELIBACC, "ELIBACC"},
    {ELIBBAD, "ELIBBAD"},
    {ELIBSCN, "ELIBSCN"},
    {ELIBMAX, "ELIBMAX"},
    {ELIBEXEC, "ELIBEXEC"},
    {EILSEQ, "EILSEQ"},
    {ERESTART, "ERESTART"},
    {ESTRPIPE, "ESTRPIPE"},
    {EUSERS, "EUSERS"},
    {ENOTSOCK, "ENOTSOCK"},
    {EDESTADDRREQ, "EDESTADDRREQ"},
    {EMSGSIZE, "EMSGSIZE"},
    {EPROTOTYPE, "EPROTOTYPE"},
    {ENOPROTOOPT, "ENOPROTOOPT"},
    {EPROTONOSUPPORT, "EPROTONOSUPPORT"},
    {ESOCKTNOSUPPORT, "ESOCKTNOSUPPORT"},
    {EOPNOTSUPP, "EOPNOTSUPP"},
    {EPFNOSUPPORT, "EPFNOSUPPORT"},
    {EAFNOSUPPORT, "EAFNOSUPPORT"},
    {EADDRINUSE, "EADDRINUSE"},
    {EADDRNOTAVAIL, "EADDRNOTAVAIL"},
    {ENETDOWN, "ENETDOWN"},
    {ENETUNREACH, "ENETUNREACH"},
    {ENETRESET, "ENETRESET"},
    {ECONNABORTED, "ECONNABORTED"},
    {ECONNRESET, "ECONNRESET"},
    {ENOBUFS, "ENOBUFS"},
    {EISCONN, "EISCONN"},
    {ENOTCONN, "ENOTCONN"},
    {ESHUTDOWN, "ESHUTDOWN"},
    {ETOOMANYREFS, "ETOOMANYREFS"},
    {ETIMEDOUT, "ETIMEDOUT"},
    {ECONNREFUSED, "ECONNREFUSED"},
    {EHOSTDOWN, "EHOSTDOWN"},
    {EHOSTUNREACH, "EHOSTUNREACH"},
    {EALREADY, "EALREADY"},
    {EINPROGRESS, "EINPROGRESS"},
    {ESTALE, "ESTALE"},
    {EUCLEAN, "EUCLEAN"},
    {ENOTNAM, "ENOTNAM"},
    {ENAVAIL, "ENAVAIL"},
    {EISNAM, "EISNAM"},
    {EREMOTEIO, "EREMOTEIO"},
    {EDQUOT, "EDQUOT"},
    {ENOMEDIUM, "ENOMEDIUM"},
    {EMEDIUMTYPE, "EMEDIUMTYPE"},
    {ECANCELED, "ECANCELED"},
    {ENOKEY, "ENOKEY"},
    {EKEYEXPIRED, "EKEYEXPIRED"},
    {EKEYREVOKED, "EKEYREVOKED"},
    {EKEYREJECTED, "EKEYREJECTED"},
    {EOWNERDEAD, "EOWNERDEAD"},
    {ENOTRECOVERABLE, "ENOTRECOVERABLE"},
    {ERFKILL, "ERFKILL"},
    {EHWPOISON, "EHWPOISON"}
};

/**
 * If the return value of the syscall is negative, print the error message
 * associated with the return value
 *
 * @param rax the return value of the system call
 */
void get_errno(long long rax)
{
    for (int i = 0; i < 133; i++) {
        if (-rax == errno_tab[i].code)
            fprintf(stderr, "-1 %s (%s)", errno_tab[i].name,
            strerror(errno_tab[i].code));
    }
}

/**
 * It prints the return value of a syscall
 *
 * @param type the type of the return value, which is one of the following:
 * @param rax the return value of the syscall
 * @param pid the process ID of the process to trace
 * @param detailed whether to show detailed information
 */
void check_ret(int type, long long rax, pid_t pid, bool detailed)
{
    fprintf(stderr, " = ");
    if (rax < 0 && detailed)
        get_errno(rax);
    else
        show(type, rax, pid, detailed);
    fprintf(stderr, "\n");
}
