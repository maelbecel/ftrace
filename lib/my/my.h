/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** @maelbecel
*/

#ifndef MY_H_
    #define MY_H_

    /**
     * @brief Color red in ANSI
    */
    #define ANSI_COLOR_RED     "\x1b[31m"

    /**
     * @brief Color green in ANSI
    */
    #define ANSI_COLOR_GREEN   "\x1b[32m"

    /**
     * @brief Color yellow in ANSI
    */
    #define ANSI_COLOR_YELLOW  "\x1b[33m"

    /**
     * @brief Color blue in ANSI
    */
    #define ANSI_COLOR_BLUE    "\x1b[34m"

    /**
     * @brief Color magenta in ANSI
    */
    #define ANSI_COLOR_MAGENTA "\x1b[35m"

    /**
     * @brief Color cyan in ANSI
    */
    #define ANSI_COLOR_CYAN    "\x1b[36m"

    /**
     * @brief Reset color in ANSI
    */
    #define ANSI_COLOR_RESET   "\x1b[0m"

    /**
     * @brief Bold text in ANSI
    */
    #define ANSI_COLOR_BOLD    "\x1b[1m"

    /**
     * @brief Underline text in ANSI
    */
    #define ANSI_COLOR_UNDERLINE "\x1b[4m"

    /**
     * @brief Blink text in ANSI
    */
    #define ANSI_COLOR_BLINK   "\x1b[5m"

    /**
     * @brief Color brown in ANSI
    */
    #define ANSI_COLOR_BROWN "\x1b[38;5;130m"

    /**
     * @brief Color orange in ANSI
    */
    #define ANSI_COLOR_ORANGE "\x1b[38;5;208m"

    /**
     * @brief Color pink in ANSI
    */
    #define ANSI_COLOR_PINK "\x1b[38;5;198m"

    /**
     * @brief Color purple in ANSI
    */
    #define ANSI_COLOR_PURPLE "\x1b[38;5;141m"

    /**
     * @brief Color grey in ANSI
    */
    #define ANSI_COLOR_GREY "\x1b[38;5;240m"

    /**
     * @brief Color dark grey in ANSI
    */
    #define ANSI_COLOR_DARKGREY "\x1b[38;5;59m"

    /**
     * @brief Color dark green in ANSI
    */
    #define ANSI_COLOR_DARKGREEN "\x1b[38;5;28m"

    /**
     * @brief Color dark blue in ANSI
    */
    #define ANSI_COLOR_DARKBLUE "\x1b[38;5;19m"

    /**
     * @brief Color dark red in ANSI
    */
    #define ANSI_COLOR_DARKRED "\x1b[38;5;124m"

    /**
     * @brief Color dark yellow in ANSI
    */
    #define ANSI_COLOR_DARKYELLOW "\x1b[38;5;226m"

    /**
     * @brief Color dark cyan in ANSI
    */
    #define ANSI_COLOR_DARKCYAN "\x1b[38;5;37m"

    /**
     * @brief Color dark purple in ANSI
    */
    #define ANSI_COLOR_DARKPURPLE "\x1b[38;5;90m"

    /**
     * @brief Color dark pink in ANSI
    */
    #define ANSI_COLOR_DARKPINK "\x1b[38;5;200m"

    /**
     * @brief Color dark orange in ANSI
    */
    #define ANSI_COLOR_DARKORANGE "\x1b[38;5;214m"

    /**
     * @brief Color dark brown in ANSI
    */
    #define ANSI_COLOR_DARKBROWN "\x1b[38;5;94m"

    /**
     * @brief More readable "or" operator
    */
    #define or ||

    /**
     * @brief More readable "and" operator
    */
    #define and &&

    /**
     * @brief More readable "not" operator
    */
    #define not !

    /**
     * @brief More readable "string" type
    */
    typedef char * string;

    /**
     * @brief More readable "array" type
    */
    typedef char ** array;

    /**
     * @brief More readable "int array" type
    */
    typedef int ** int_array;

    /**
     * @brief Shorter "unsigned int" type
    */
    typedef unsigned int uint;

    /**
     * Give the absolute value of a number
     *
     * @param x number to check
     *
     * @return absolute value of the number in argument
    */
    #define ABS(x) ((x) < 0 ? -(x) : (x))

    /**
     * Execute a foreach loop
     *
     * @param array Array to loop through
     * @param fcnt Function to execute in the foreach loop
     *
    */
    #define FOREACH(array, fcnt) for (const size_t FE = 0; array[FE] != NULL; \
            FE++) { \
                fcnt; \
                }

    /**
     * Set a variable as unused
    */
    #define UNUSED __attribute__((unused))

    /**
     * Give the size of an array
     *
     * @param arr Array to check
     *
     * @return Absolute value of the number in argument
    */
    #define ARRAY_SIZE(arr) (!arr[0]) ? (sizeof(arr) / sizeof(arr[0])) : 0

    /**
     * Give the concatenation of two int
     *
     * @param a First int to concatenate
     * @param b Second int to concatenate
     *
     * @return Concatenated string of the two int
    */
    #define MERGE(a, b) a##b

    /**
     * Change the argument to a string
     *
     * @param x Anything
     *
     * @return The string of the argument
    */
    #define STR(x) #x

    /**
    * It writes a single character to the standard output
    *
    * @param c the character to print
    */
    void my_putchar(char c);

    /**
    * It compares each element of the array to the next element, and if
    * the next element is smaller, it swaps them
    *
    * @param tab the array to be sorted
    * @param size the number of elements in the array
    */
    void my_sort_int_array(int *tab, int size);

    /**
    * Swap the values of two integers.
    *
    * @param a a pointer to an integer
    * @param b pointer to an integer
    */
    void my_swap(int *a, int *b);

    /**
    * It prints either a P or an N depending on whether the integer passed
    * to it is positive or negative
    *
    * @param nb the number to be checked
    *
    * @return 0.
    */
    int my_isneg(int nb);

    /**
    * It prints a number
    *
    * @param nb the number to print
    *
    * @return 0
    */
    int my_put_nbr(int nb);

    /**
    * It writes the string str to the standard output
    *
    * @param str the string to be printed
    *
    * @return 0
    */
    int my_putstr(char const *str);

    /**
    * It returns the length of a string
    *
    * @param str This is the string we want to find the length of.
    *
    * @return The length of the string.
    */
    int my_strlen(char const *str);

    /**
    * It takes a string and returns the number it contains
    *
    * @param str The string to be parsed.
    *
    * @return The number in the string.
    */
    int my_getnbr(char const *str);

    /**
    * It takes a number and a power, and returns the number to the power
    *
    * @param nb the number to be powered
    * @param p the power to which we want to raise the number
    *
    * @return the result of the power function.
    */
    int my_compute_power_rec(int nb, int power);

    /**
    * It returns the number of digits in an integer
    *
    * @param x The number to get the length of.
    *
    * @return The number of digits in the integer.
    */
    int my_intlen(int x);

    /**
    * It computes the square root of a number
    *
    * @param nb the number to compute the square root of
    *
    * @return The square root of the number given as parameter.
    */
    int my_compute_square_root(int nb);

    /**
    * It returns 0 if the number is prime, 1 if it's not
    *
    * @param nb the number to be tested
    *
    * @return the number of prime numbers found.
    */
    int my_is_prime(int nb);

    /**
    * It returns the next prime number after the number given as parameter
    *
    * @param nb the number to find the prime number above
    *
    * @return The next prime number after the number given as a parameter.
    */
    int my_find_prime_sup(int nb);

    /**
    * It compares two strings and returns the difference between the first
    * characters that are different
    *
    * @param s1 The first string to compare.
    * @param s2 the string to compare to
    *
    * @return an integer less than, equal to, or greater than zero if s1 is
    * found, respectively, to be less than, to match, or be greater than s2.
    */
    int my_strcmp(char const *s1, char const *s2);

    /**
    * It compares the first n characters of two strings and returns the
    * difference between the first characters that are different
    *
    * @param s1 The first string to compare.
    * @param s2 The string to compare to.
    * @param n the number of characters to compare
    *
    * @return The difference between the two strings.
    */
    int my_strncmp(char const *s1, char const *s2, int n);

    /**
    * If the first character of the string is a null character, return 1,
    * otherwise, while the current character is not a null character, if the
    * current character is not between 'a' and 'z', inclusive, return 0,
    * otherwise, increment the counter and continue.
    *
    * @param str a string
    *
    * @return 1 if the string is lowercase, 0 if not.
    */
    int my_str_islower(char const *str);

    /**
    * It returns 1 if the string is only made up of digits, and 0 otherwise
    *
    * @param str a string
    *
    * @return 1 if the string contains only digits, otherwise it returns 0.
    */
    int my_str_isnum(char const *str);

    /**
    * If the string is empty, return 1, otherwise, if the string contains a
    * character that is not a printable character, return 0, otherwise return 1
    *
    * @param str The string to be checked.
    *
    * @return 1 if the string is printable, otherwise it returns 0.
    */
    int my_str_isprintable(char const *str);

    /**
    * If the string is empty, return 1, otherwise, if the string contains a
    * character that is not an uppercase letter, return 0, otherwise, return 1
    *
    * @param str a string
    *
    * @return 1 if the string is uppercase, otherwise it returns 0.
    */
    int my_str_isupper(char const *str);

    /**
    * my_showmem() returns 0.
    *
    * @param str Unused parameter
    * @param size Unused parameter
    *
    * @return 0
    */
    int my_showmem(char const *str, int size);

    /**
    * my_showstr() returns 0.
    *
    * @param str Unused parameter
    *
    * @return 0
    */
    int my_showstr(char const *str);

    /**
    * If the string is empty, return 1, otherwise, if the string contains any
    * characters that are not between 'a' and 'z' or 'A' and 'Z', return 0,
    * otherwise return 1
    *
    * @param str a string
    *
    * @return 1 if the string is alphabetical, 0 if not.
    */
    int my_str_isalpha(char const *str);

    /**
    * It prints the strings in the array, one after the other, until it reaches
    * the end of the array
    *
    * @param tab a pointer to a pointer to a char.
    *
    * @return The number of characters printed.
    */
    int my_show_word_array(char * const *tab);

    /**
    * It returns the number of strings in a NULL-terminated array of strings
    *
    * @param str The array of strings to be counted.
    *
    * @return The number of elements in the array.
    */
    int my_strarraylen(char **str);

    /**
    * Copy the string pointed to by src, including the terminating null byte
    * ('\0'), to the buffer pointed to by dest
    *
    * @param dest This is the destination array, which should contain the copy
    * @param src This is the string that we want to copy.
    *
    * @return The address of the destination string.
    */
    char *my_strcpy(char const *src);

    /**
    * Copy the first n characters of src into dest
    *
    * @param dest This is the destination string.
    * @param src The string to be copied.
    * @param n the number of characters to copy
    *
    * @return The address of the destination string.
    */
    char *my_strncpy(char *dest, char const *src, int n);

    /**
    * It reverses a string
    *
    * @param str The string to reverse.
    *
    * @return The address of the first character of the string.
    */
    char *my_revstr(char *str);

    /**
    * It returns a pointer to the first occurrence of the string to_find in the
    * string str
    *
    * @param str The string to search in
    * @param to_find the string to find
    *
    * @return The address of the first character of the first occurence of the
    * string to_find in the string str.
    */
    char *my_strstr(char *str, char const *to_find);

    /**
    * It takes a string and returns a string with all lowercase letters
    * converted to uppercase
    *
    * @param str a string
    *
    * @return The address of the first character of the string.
    */
    char *my_strupcase(char *str);

    /**
    * It takes a string and converts all uppercase letters to lowercase
    *
    * @param str This is the string to be converted.
    *
    * @return The address of the first character of the string.
    */
    char *my_strlowcase(char *str);

    /**
    * It capitalizes the first letter of each word in a string
    *
    * @param str a string
    *
    * @return The address of the first character of the string.
    */
    char *my_strcapitalize(char *str);

    /**
    * It copies the string pointed to by src to the end of the string pointed
    * to by dest
    *
    * @param dest This is the destination string.
    * @param src This is the string that we want to append to the end of dest.
    *
    * @return The address of the first character of the string.
    */
    char *my_strcat(char *dest, char const *src);

    /**
    * It copies the first n characters of src to the end of dest
    *
    * @param dest the destination string
    * @param src The string to be appended.
    * @param nb the number of characters to append
    *
    * @return The address of the first character of the string.
    */
    char *my_strncat(char *dest, char const *src, int nb);

    /**
    * It allocates a new string, copies the contents of the original string into
    * the new string, and returns a pointer to the new string
    *
    * @param str The string to be copied.
    *
    * @return A pointer to a new string.
    */
    char *my_strdup(char const *str);

    /**
    * It takes three strings,
    * concatenates them, and returns the result
    *
    * @param before the string before the match
    * @param mid the middle part of the string
    * @param after the string to be appended to the end of the new string
    *
    * @return A pointer to a string.
    */
    char *concat(char *before, char *mid, char *after);

    /**
    * It converts an integer into a string
    *
    * @param num the number to convert
    *
    * @return a string that is the number passed as a parameter.
    */
    char *inttochar(int nb);

    /**
    * It takes a string and a separator, and returns an array of strings, each
    * string being a word from the original string, separated by the separator
    *
    * @param str The string to be converted.
    * @param separator the character that separates the words in the string
    *
    * @return an array of strings.
    */
    char **my_str_to_word_array(char *str, char sep);

#endif
