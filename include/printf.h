/*
** EPITECH PROJECT, 2021
** printf.h
** File description:
** @maelbecel
*/

#ifndef PRINTF_H_
    #define PRINTF_H_
    #include <stdarg.h>
    #include <unistd.h>
    #include <stdlib.h>

    #define DEBUG_MODE 1

    #if DEBUG_MODE == 1
        /*
        * It's a macro that will print the file name, the line number
        * and the string passed as parameter.
        *
        * @param x String to display
        */
        #define OUT(x) my_printf("\x1b[33m\x1b[1m[LOG]\x1b[0m %s:%d (%s)\n", \
                        __FILE__,__LINE__, x)

        /*
        * It's a macro that will print the file name, the line number
        * and the string passed as parameter depending if the test passed.
        *
        * @param cond Conditional testing
        */
        #define ASSERT(cond) \
        if (!(cond)) { \
            my_printf("\x1b[31m\x1b[1m[ASSERT FAILED]\x1b[0m %s:%d (%s)\n", \
            __FILE__, __LINE__, #cond); \
            exit(84); \
        } else { \
            my_printf("\x1b[32m\x1b[1m[ASSERT PASSED]\x1b[0m %s:%d (%s)\n", \
            __FILE__, __LINE__, #cond); \
        }
    #else
        #define OUT(x) my_printf("")
        #define ASSERT(cond) my_printf("")
    #endif

    /**
    * It display a char
    *
    * @param argv the va_list variable
    *
    * @return EXIT_SUCCESS
    */
    int displaychar(va_list argv);

    /**
    * It prints a string.
    *
    * @param argv the list of arguments
    *
    * @return EXIT_SUCCESS
    */
    int displaystr(va_list argv);

    /**
    * It takes an integer as an argument, and displays it on the standard
    * output
    *
    * @param argv the list of arguments
    *
    * @return EXIT_SUCCESS
    */
    int displaynbr(va_list argv);

    /**
    * It takes an long integer as an argument, and displays it on the standard
    * output
    *
    * @param argv the list of arguments
    *
    * @return EXIT_SUCCESS
    */
    int displaynbr_long(va_list argv);

    /**
    * It takes an integer as an argument, and displays it on the standard
    * output in binary format.
    *
    * @param argv the list of arguments
    *
    * @return EXIT_SUCCESS
    */
    int displaybinary(va_list argv);

    /**
    * It display a "%" symbol in standard output.
    *
    * @param argv the list of arguments
    *
    * @return EXIT_SUCCESS
    */
    int displaypercent(va_list argv);

    /**
    * It display a string in base 16 from the pointer in the standard output.
    *
    * @param nb the number to be converted
    *
    * @return EXIT_SUCCESS
    */
    int displaypointer(va_list argv);

    /**
    * It display a number in base 16 in the standard output.
    *
    * @param nb the number to be converted
    *
    * @return EXIT_SUCCESS
    */
    int displaynbr_hexa(va_list argv);

    /**
    * It display a number in base 16 upcased in the standard output.
    *
    * @param nb the number to be converted
    *
    * @return EXIT_SUCCESS
    */
    int displaynbr_hexa_capital(va_list argv);

    /**
    * It takes a string and prints it, but if a character is unprintable,
    * it prints it as an octal escape sequence
    *
    * @param argv the list of arguments
    *
    * @return EXIT_SUCCESS
    */
    int displaystr_unprintable(va_list argv);

    /**
    * It display a number in base 10 in the standard output.
    *
    * @param nb the number to be converted
    *
    * @return EXIT_SUCCESS
    */
    int displaynbr_dec(va_list argv);

    /**
    * It display a number in base 8 in the standard output.
    *
    * @param nb the number to be converted
    *
    * @return EXIT_SUCCESS
    */
    int displaynbr_octal(va_list argv);

    /**
    * It display a number in base 8 in the standard output.
    *
    * @param nb the number to be converted
    *
    * @return EXIT_SUCCESS
    */
    int displaynbr_octal_hashtag(va_list argv);

    /**
    * It display a number in base 16 in the standard output.
    *
    * @param nb the number to be converted
    *
    * @return EXIT_SUCCESS
    */
    int displaynbr_hexa_hashtag(va_list argv);

    /**
    * It display a number in base 16 upcased in the standard output.
    *
    * @param nb the number to be converted
    *
    * @return EXIT_SUCCESS
    */
    int displaynbr_hexa_capital_hashtag(va_list argv);

    /**
    * It takes a string and a list of arguments, and displays
    * the string with the arguments in it
    *
    * @param str the string to be displayed
    * @param ... the arguments to be displayed
    *
    * @return the number of characters printed.
    */
    int my_printf(char const *str, ...);

    /**
    * It's a struct that contains a pointer on function and a flag.
    *
    * @param func pointer to the function
    * @param flag the flag associated with the function
    */
    struct flags {
        int(*func)(va_list);
        char flag;
    };

#endif
