/*
** EPITECH PROJECT, 2023
** B-PSU-400-REN-4-1-ftrace-mael1.becel
** File description:
** print
*/

#ifndef PRINT_H_
    #define PRINT_H_

    #include "syscalls.h"
    #include "ftrace.h"

    void print_syscall(syscall_t syscall, struct user_regs_struct regs, int pid,
    bool detailed);
    void print_struct_stat(unsigned long long args, pid_t pid);
    void print_num(unsigned long long arg, pid_t pid);
    void print_string(unsigned long long arg, pid_t pid);
    void print_void_ptr(unsigned long long arg, pid_t pid);
    void print_pointer(unsigned long long arg, pid_t pid);
    void print_string_array(unsigned long long args, pid_t pid);
    void print_env(unsigned long long args, pid_t pid);

    struct print_s {
        int id;
        void (*print)(unsigned long long, int);
    };

    typedef struct charbs_s {
        int id;
        char *name;
    } charbs_t;

    static print_t print_table[129] = {
        {NUM, &print_num},
        {STRING, &print_string},
        {STRING_ARRAY, &print_string_array},
        {UNSIGNED, &print_pointer},
        {VOID_P, &print_void_ptr},
        {CONST_VOID_P, &print_pointer},
        {STRUCT_P, &print_pointer},
        {STRUCT_STAT_P, &print_struct_stat},
        {STRUCT_FD_P, &print_pointer},
        {PVOID, &print_pointer},
        {CONST_KERNEL_SIGSET_T_P, &print_pointer},
        {KERNEL_SIGSET_T_P, &print_pointer},
        {VARGS, &print_pointer},
        {CONST_STRUCT_IOVEC_P, &print_pointer},
        {FD_SET_P, &print_pointer},
        {STRUCT_TIMEVAL_P, &print_pointer},
        {VOID, &print_pointer},
        {STRUCT_SHMID_DS_P, &print_pointer},
        {CONST_STRUCT_TIMESPEC_P, &print_pointer},
        {STRUCT_TIMESPEC_P, &print_pointer},
        {STRUCT_ITIMERVAL_P, &print_pointer},
        {CONST_STRUCT_ITIMERVAL_P, &print_pointer},
        {CONST_STRUCT_SOCKADDR_P, &print_pointer},
        {SOCKLEN_T, &print_pointer},
        {STRUCT_SOCKADDR_P, &print_pointer},
        {SOCKLEN_T_P, &print_pointer},
        {CONST_STRUCT_MSGHDR_P, &print_pointer},
        {STRUCT_MSGHDR_P, &print_pointer},
        {STRUCT_RUSAGE_P, &print_pointer},
        {STRUCT_UTSNAME_P, &print_pointer},
        {STRUCT_SEMBUF_P, &print_pointer},
        {STRUCT_MSQID_DS_P, &print_pointer},
        {STRUCT_LINUX_DIRENT_P, &print_pointer},
        {MODE_T, &print_pointer},
        {UID_T, &print_pointer},
        {GID_T, &print_pointer},
        {STRUCT_TIMEZONE_P, &print_pointer},
        {STRUCT_RLIMIT_P, &print_pointer},
        {CLOCK_T, &print_pointer},
        {STRUCT_TMS_P, &print_pointer},
        {ENUM_____REQUEST, &print_pointer},
        {CONST_GID_T_P, &print_pointer},
        {UID_T_P, &print_pointer},
        {GID_T_P, &print_pointer},
        {CAP_USER_HEADER_T, &print_pointer},
        {CAP_USER_DATA_T, &print_pointer},
        {CONST_CAP_USER_DATA_T, &print_pointer},
        {CONST_STACK_T_P, &print_pointer},
        {STACK_T_P, &print_pointer},
        {CONST_STRUCT_UTIMBUF_P, &print_pointer},
        {DEV_T, &print_pointer},
        {STRUCT_STATFS_P, &print_pointer},
        {ID_T, &print_pointer},
        {CONST_STRUCT_SCHED_PARAM_P, &print_pointer},
        {STRUCT_SCHED_PARAM_P, &print_pointer},
        {STRUCT_TIMESPEC_P_, &print_pointer},
        {STRUCT____ARGS_P, &print_pointer},
        {STRUCT_TIMEX_P, &print_pointer},
        {CONST_STRUCT_RLIMIT_P, &print_pointer},
        {CONST_STRUCT_TIMEVAL_P, &print_pointer},
        {CONST_STRUCT_TIMEZONE_P, &print_pointer},
        {CADDR_T, &print_pointer},
        {STRUCT_KERNEL_SYM_P, &print_pointer},
        {NUM_P, &print_pointer},
        {STRUCT_NFSCTL_ARG_P, &print_pointer},
        {UNION_NFSCTL_RES_P, &print_pointer},
        {OFF64_T, &print_pointer},
        {TIME_T, &print_pointer},
        {_T___T_P, &print_pointer},
        {CONST_CPU_SET_T_P, &print_pointer},
        {CPU_SET_T_P, &print_pointer},
        {STRUCT_USER_DESC_P, &print_pointer},
        {AIO_CONTEXT_T_P, &print_pointer},
        {AIO_CONTEXT_T, &print_pointer},
        {STRUCT_IO_EVENT_P, &print_pointer},
        {STRUCT_IOCB_P, &print_pointer},
        {U64, &print_pointer},
        {STRUCT_LINUX_DIRENT64_P, &print_pointer},
        {CLOCKID_T, &print_pointer},
        {STRUCT_SIGEVENT_P, &print_pointer},
        {TIMER_T_P, &print_pointer},
        {TIMER_T, &print_pointer},
        {CONST_STRUCT_ITIMERSPEC_P, &print_pointer},
        {STRUCT_ITIMERSPEC_P, &print_pointer},
        {STRUCT_EPOLL_EVENT_P, &print_pointer},
        {CONST_STRUCT_TIMEVAL, &print_pointer},
        {CONST_UNSIGNED_P, &print_pointer},
        {UNSIGNED_P, &print_pointer},
        {MQD_T, &print_pointer},
        {CONST_STRUCT_SIGEVENT_P, &print_pointer},
        {STRUCT_MQ_ATTR_P, &print_pointer},
        {STRUCT_KEXEC_SEGMENT_P, &print_pointer},
        {IDTYPE_T, &print_pointer},
        {SIGINFO_T_P, &print_pointer},
        {KEY_SERIAL_T, &print_pointer},
        {UNUM32_T, &print_pointer},
        {STRUCT_POLLFD_P, &print_pointer},
        {CONST_SIGSET_T_P, &print_pointer},
        {STRUCT_ROBUST_LIST_HEAD_P, &print_pointer},
        {LNUM_P, &print_pointer},
        {CONST_NUM_P, &print_pointer},
        {CONST_STRUCT_TIMESPEC, &print_pointer},
        {STRUCT_PERF_EVENT_ATTR_P, &print_pointer},
        {STRUCT_MMSGHDR_P, &print_pointer},
        {UNUM64_T, &print_pointer},
        {STRUCT_FILE_HANDLE_P, &print_pointer},
        {STRUCT__CACHE_P, &print_pointer},
        {STRUCT_SCHED_ATTR_P, &print_pointer},
        {UNION__ATTR_P, &print_pointer},
        {ENV, &print_env},
        {-1, NULL}
    };

#endif
