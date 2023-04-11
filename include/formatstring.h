/*
** EPITECH PROJECT, 2021
** formatstring.h
** File description:
** @maelbecel
*/

#ifndef FORMATSTRING_H_
    #define FORMATSTRING_H_
    #include <stdarg.h>
    #include <unistd.h>

    /**
    * Struct for a flag to format,
    * contains a pointer on function for the flag and the flag
    *
    * @param func pointer to the function
    * @param flag flag associated with the function
    */
    struct fflags {
        char *(*func)(va_list);
        char flag;
    };

    /**
    * It converts an integer to a binary string
    *
    * @param argv The va_list variable that contains the arguments.
    *
    * @return A string containing the binary representation of the number
    * passed as argument.
    */
    char *fdisplaybinary(va_list argv);

    /**
    * It takes a character,
    * converts it to a string, and returns the string
    *
    * @param argv The va_list variable that contains the arguments.
    *
    * @return A pointer to a string.
    */
    char *fdisplaychar(va_list argv);

    /**
    * It converts an integer to a  string
    *
    * @param argv The va_list variable that contains the arguments.
    *
    * @return A string containing the representation of the number
    * passed as argument.
    */
    char *fdisplaynbr_dec(va_list argv);

    /**
    * It converts an integer to a hexadecimal string upcased.
    *
    * @param argv The va_list variable that contains the arguments.
    *
    * @return A string containing the upcased hexadecimal representation of
    * the number passed as argument.
    */
    char *fdisplaynbr_hexa_capital(va_list argv);

    /**
    * It converts an integer to a hexadecimal string upcased.
    *
    * @param argv The va_list variable that contains the arguments.
    *
    * @return A string containing the upcased hexadecimal representation of
    * the number passed as argument.
    */
    char *fdisplaynbr_hexa_capital_hashtag(va_list argv);

    /**
    * It converts an integer to a hexadecimal string.
    *
    * @param argv The va_list variable that contains the arguments.
    *
    * @return A string containing the hexadecimal representation of
    * the number passed as argument.
    */
    char *fdisplaynbr_hexa(va_list argv);

    /**
    * It converts an integer to a hexadecimal string.
    *
    * @param argv The va_list variable that contains the arguments.
    *
    * @return A string containing the hexadecimal representation of
    * the number passed as argument.
    */
    char *fdisplaynbr_hexa_hashtag(va_list argv);

    /**
    * It converts an integer to an octal string.
    *
    * @param argv The va_list variable that contains the arguments.
    *
    * @return A string containing the octal representation of
    * the number passed as argument.
    */
    char *fdisplaynbr_octal(va_list argv);

    /**
    * It converts an integer to an octal string.
    *
    * @param argv The va_list variable that contains the arguments.
    *
    * @return A string containing the octal representation of
    * the number passed as argument.
    */
    char *fdisplaynbr_octal_hashtag(va_list argv);

    /**
    * It converts a long integer to a string.
    *
    * @param argv The va_list variable that contains the arguments.
    *
    * @return A string containing the representation of
    * the number passed as argument.
    */
    char *fdisplaynbr_long(va_list argv);

    /**
    * It converts an integer to an octal string.
    *
    * @param argv The va_list variable that contains the arguments.
    *
    * @return A string containing the octal representation of
    * the number passed as argument.
    */
    char *fdisplaypercent(__attribute__((unused))va_list argv);

    /**
    * It returns a string containing a percent sign
    *
    * @param argv unused parameter.
    *
    * @return A pointer to a string.
    */
    char *fdisplaypointer(va_list argv);

    /**
    * It takes a string and returns a string with all unprintable characters
    * replaced by their octal representation
    *
    * @param argv The va_list variable that contains the arguments.
    *
    * @return The string.
    */
    char *fdisplaystr_unprintable(va_list argv);

    /**
    * It converts an integer to an octal string.
    *
    * @param nb The number to convert.
    *
    * @return A string containing the octal representation of
    * the number passed as argument.
    */
    char *fdisplayoctal(int nb);

    /**
    * It takes two strings and returns a new string that is the concatenation
    * of the two strings
    *
    * @param a The first string to be concatenated.
    * @param b the string to be appended to the end of a
    *
    * @return A pointer to a string.
    */
    char *fus(char *a, char *b);

    /**
    * It takes a string as an argument and returns the same string.
    *
    * @param argv The va_list variable that contains the arguments.
    *
    * @return A pointer to a string.
    */
    char *fdisplaystr(va_list argv);

    /**
    * It takes an integer,
    * converts it to a string, and returns the string
    *
    * @param argv the list of arguments
    *
    * @return A pointer to a string.
    */
    char *fdisplaynbr(va_list argv);

    /**
    * It takes a string and a list of arguments, and returns a string that
    * is the concatenation of the arguments in the string.
    *
    * @param str The string to format.
    * @param ... The list of arguments.
    *
    * @return A pointer to string
    */
    char *format(char const *str, ...);

#endif
